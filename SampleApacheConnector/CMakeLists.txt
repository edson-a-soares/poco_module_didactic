SET(SAMPLE_DIRECTORY_NAME "SampleApacheConnector")
SET(SAMPLE_BINARY_NAME "sample_apache_connector")

# Application directory name
SET(APPLICATION_DIRECTORY_NAME "${SAMPLE_DIRECTORY_NAME}")
# Target directory for the main file of the application
SET(APPLICATION_EXECUTABLE_DIRECTORY "/usr/local/bin")
# Other application binary's files hosting directory
SET(APPLICATION_HOSTING_DIRECTORY "/usr/local/lib/${APPLICATION_DIRECTORY_NAME}")

# Apache2 target directories
set(APACHE_MODULE_BINARY_TARGET_DIRECTORY "/usr/lib/apache2/modules")
set(APACHE_MODULE_CONFIG_TARGET_DIRECTORY "/etc/apache2/mods-available")

add_subdirectory(Application)
add_subdirectory(Launcher)
