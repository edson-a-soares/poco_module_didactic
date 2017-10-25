
    include settings
    include settings::configure

    include gcc
    include gcc::install

    include cmake
    include cmake::install

    include poco
    include poco::install
    include poco::install_apache_connector

    Class[ "settings::configure" ]              ->
    Class[ "gcc::install" ]                     ->
    Class[ "cmake::install" ]                   ->
    Class[ "poco::install" ]                    ->
    Class[ "poco::install_apache_connector" ]
