#!/bin/bash

APPLICATION_ENVIRONMENT=$1

sed -i -e '$a export APPLICATION_ENVIRONMENT='$APPLICATION_ENVIRONMENT'' /etc/apache2/envvars
a2enmod poco



