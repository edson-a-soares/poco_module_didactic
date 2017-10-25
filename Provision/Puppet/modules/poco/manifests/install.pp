class poco::install {

    include settings::configure

    $poco_library_url = "https://pocoproject.org/releases/poco-1.7.8/poco-1.7.8-all.tar.gz"

    exec { "wget-poco":
        command => "wget $poco_library_url --directory-prefix=$settings::configure::home_directory",
        unless  => "test -d /usr/local/include/Poco",
        path    => [ "/bin", "/usr/bin" ],
    }

    exec { "uncompress-poco":
        cwd         => "$settings::configure::home_directory",
        command	    => "tar -xf poco-1.7.8-all.tar.gz",
        user        => $settings::configure::home_username,
        group       => $settings::configure::home_group,
        subscribe   => Exec[ "wget-poco" ],
        refreshonly => true,
        path        => [ "/bin", "/usr/bin" ],
    }

    exec { "configure-poco":
        cwd         => "$settings::configure::home_directory/poco-1.7.8-all",
        command	    => "sudo sh configure --no-tests --no-samples --minimal",
        subscribe   => Exec[ "uncompress-poco" ],
        user        => $settings::configure::home_username,
        group       => $settings::configure::home_group,
        refreshonly => true,
        path        => [ "/bin", "/usr/bin" ],
    }

    exec { "install-poco":
        cwd         => "$settings::configure::home_directory/poco-1.7.8-all",
        command	    => "sudo make && sudo make install",
        subscribe   => Exec[ "configure-poco" ],
        refreshonly => true,
        timeout     => 0,
        logoutput   => true,
        path        => [ "/bin", "/usr/bin" ],
    }

}
