class cmake::install {

    include settings::configure

    $cmake_directory = "cmake-3.7.2"
    $cmake_file_name = "cmake-3.7.2.tar.gz"
    $cmake_url = "https://cmake.org/files/v3.7/cmake-3.7.2.tar.gz"

    exec { "wget-cmake":
        command => "wget $cmake_url --directory-prefix=$settings::configure::home_directory",
        unless  => "test -f $settings::configure::home_directory/$cmake_file_name",
        user    => $settings::configure::home_username,
        group   => $settings::configure::home_group,
        path    => [ "/bin", "/usr/bin" ],
    }

    exec { "uncompress-cmake":
        cwd         => "$settings::configure::home_directory",
        command	    => "tar -xf $cmake_file_name",
        subscribe   => Exec[ "wget-cmake" ],
        user        => $settings::configure::home_username,
        group       => $settings::configure::home_group,
        refreshonly => true,
        logoutput   => true,
        path        => [ "/bin", "/usr/bin" ],
    }

    exec { "configure-cmake":
        cwd         => "$settings::configure::home_directory/$cmake_directory",
        command	    => "sh configure",
        subscribe   => Exec[ "uncompress-cmake" ],
        user        => $settings::configure::home_username,
        group       => $settings::configure::home_group,
        refreshonly => true,
        logoutput   => true,
        timeout     => 0,
        path        => [ "/bin", "/usr/bin" ],
    }

    exec { "install-cmake":
        cwd         => "$settings::configure::home_directory/$cmake_directory",
        command	    => "sudo make && sudo make install",
        subscribe   => Exec[ "configure-cmake" ],
        refreshonly => true,
        logoutput   => true,
        timeout     => 0,
        path        => [ "/bin", "/usr/bin" ],
    }

}
