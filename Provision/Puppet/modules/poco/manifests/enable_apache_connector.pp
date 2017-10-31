class poco::enable_apache_connector {

    include settings::configure

    $poco_module = "poco_module"

    exec { "enable-poco-module":
        command  => "a2enmod $poco_module",
        provider => shell,
        user     => root,
        group    => root,
        path     => [ "/bin", "/usr/sbin", "/usr/bin" ],
    }

    exec { "apache-restarting":
        command	    => "service apache2 restart",
        subscribe   => Exec[ "enable-poco-module" ],
        refreshonly => true,
        user        => root,
        group       => root,
        path        => [ "/bin", "/usr/local/bin", "/usr/bin" ],
    }

}
