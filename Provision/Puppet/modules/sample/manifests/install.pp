class sample::install {

    include settings::configure

    $sample_repository_name = "poco_module_didactic"
    $sample_library_target_directory = "/usr/local/lib/SampleApacheConnector"
    $sample_repository_url = "https://github.com/edson-a-soares/poco_module_didactic.git"

    exec { "git-clone-sample":
        cwd     => "$settings::configure::home_directory",
        command => "git clone $sample_repository_url",
        unless  => "test -d $settings::configure::home_directory/$sample_repository_name",
        path    => [ "/bin", "/usr/bin" ],
    }

    exec { "build-sample":
        cwd         => "$settings::configure::home_directory/$sample_repository_name",
        command	    => "cmake .",
        subscribe   => Exec[ "git-clone-sample" ],
        refreshonly => true,
        user        => root,
        group       => root,
        path        => [ "/bin", "/usr/local/bin", "/usr/bin" ],
    }

    exec { "compile-sample":
        cwd         => "$settings::configure::home_directory/$sample_repository_name",
        command	    => "make",
        subscribe   => Exec[ "build-sample" ],
        refreshonly => true,
        user        => root,
        group       => root,
        path        => [ "/bin", "/usr/bin" ],
    }

    exec { "install-sample":
        cwd         => "$settings::configure::home_directory/$sample_repository_name",
        command	    => "make install",
        unless      => "test -d $sample_library_target_directory",
        subscribe   => Exec[ "compile-sample" ],
        refreshonly => true,
        path        => [ "/bin", "/usr/bin" ],
    }

}
