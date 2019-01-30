#!/bin/bash

APPLICATION_VERSION=$1
APPLICATION_ENVIRONMENT=$2

# Insert application environment variables
sed -i -e '$a export APPLICATION_VERSION='$APPLICATION_VERSION'' /etc/apache2/envvars
sed -i -e '$a export APPLICATION_ENVIRONMENT='$APPLICATION_ENVIRONMENT'' /etc/apache2/envvars

# Enable Poco ApacheConnector
a2enmod poco
