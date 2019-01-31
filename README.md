# Poco ApacheConnector Sample

[![License](https://img.shields.io/badge/License-Apache%202.0-blue.svg)](LICENSE.md)

### Overview 

That is a simple application example created using [Poco C++ Libraries](https://pocoproject.org). 
ApacheConnector is a Poco module that allows one to run C++ applications built using Poco Framework on Apache Server. 
The purpose of this sample is showing a bit more about running an Poco C++ application over ApacheConnector than what is available on Poco documentation.

### Requirements for running it

- Docker

### Running the application

For starting the application:

```bash
docker build -t poco-apacheconnector-sample .
docker run -p8080:80 -d poco-apacheconnector-sample 
```

For following its execution reach Apache access and error logs:

```bash
docker ps
docker exec -it CONTAINER ID /bin/bash
# tail -f /var/log/apache2/error.log
```

Now, just access the address **http://localhost:8080** on your favorite web browser. 

For destroying the environment:

```bash
docker ps
docker stop CONTAINER ID
```

### Standards and Style

This project do not follow any specific **Coding Style Guidelines or Standard**. But, it has been influenced by [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html), 
[PPP Style Guide](http://www.stroustrup.com/Programming/PPP-style-rev3.pdf) and [Applied Informatics C++ Coding Style Guide](https://www.appinf.com/download/CppCodingStyleGuide.pdf) itself.  

### Useful links

* [JSON API](http://jsonapi.org)
* [Poco C++ Libraries](https://pocoproject.org)
* [Google Test](https://github.com/google/googletest/blob/master/googletest/docs/Primer.md)
