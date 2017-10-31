class poco::install_apache_connector {

    include settings::configure

    $poco_module_target_name = "mod_poco.so"
    $poco_module_source_name = "libmod_poco.so"
    $apache_module_target_path = "/usr/lib/apache2/modules"
    $poco_repository_alias = "poco_clone"
    $poco_repository_url = "https://github.com/pocoproject/poco.git"

    exec { "clone-poco":
        cwd     => "$settings::configure::home_directory",
        command => "git clone $poco_repository_url $poco_repository_alias",
        unless  => "test -d $settings::configure::home_directory/$poco_repository_alias",
        timeout => 0,
        path    => [ "/bin", "/usr/bin" ],
    }

    exec { "build-poco":
        cwd         => "$settings::configure::home_directory/$poco_repository_alias",
        command	    => "cmake . -DENABLE_APACHECONNECTOR=ON",
        subscribe   => Exec[ "clone-poco" ],
        user        => root,
        group       => root,
        refreshonly => true,
        logoutput   => true,
        path        => [ "/bin", "/usr/local/bin", "/usr/bin" ],
    }

    exec { "compile-apache-connector":
        cwd         => "$settings::configure::home_directory/$poco_repository_alias/ApacheConnector",
        command	    => "make",
        subscribe   => Exec[ "build-poco" ],
        refreshonly => true,
        user        => root,
        group       => root,
        timeout     => 0,
        logoutput   => true,
        path        => [ "/bin", "/usr/bin" ],
    }

    exec { "install-poco-module":
        cwd         => "$settings::configure::home_directory/$poco_repository_alias/lib",
        command	    => "sudo cp $poco_module_source_name $apache_module_target_path/$poco_module_target_name",
        unless      => "test -f $apache_module_target_path/$poco_module_target_name",
        subscribe   => Exec[ "compile-apache-connector" ],
        refreshonly => true,
        logoutput   => true,
        path        => [ "/bin", "/usr/bin" ],
    }

    file { "/etc/apache2/mods-available/poco_module.load":
      ensure	      => file,
      source	      => "puppet:///modules/poco/mods-available/poco_module.load",
      subscribe     => Exec[ "install-poco-module" ],
      group	        => root,
      owner	        => root
    }

}
