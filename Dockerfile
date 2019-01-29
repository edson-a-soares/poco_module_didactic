FROM edsonsoares/poco:1.9-ubuntu

ENV DEBIAN_FRONTEND noninteractive

ENV CMAKE_DIRECTORY_NAME cmake-3.7.2
ENV CMAKE_FILE_NAME cmake-3.7.2.tar.gz
ENV CMAKE_DOWNLOAD_URL https://cmake.org/files/v3.7/cmake-3.7.2.tar.gz
ENV CMAKE_SHA256 dc1246c4e6d168ea4d6e042cfba577c1acd65feea27e56f5ff37df920c30cae0

# Install application dependencies
RUN apt-get update -qq \
	&& apt-get install -yq software-properties-common python-software-properties \
	&& apt-add-repository ppa:ubuntu-toolchain-r/test \
	&& apt-get update \
	# Install CMake 3.7.2, GCC/G++ 6 and other dependencies
	&& apt-get install -yq --no-install-recommends \
		curl \
		git \
		libssl-dev \
		apt-utils \
		build-essential \
		unixodbc \
		unixodbc-dev \
		ca-certificates \
		libncurses-dev \
		pkg-config \
		cmake \
		gcc-6 \
		g++-6 \
	&& update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-6 60 --slave /usr/bin/g++ g++ /usr/bin/g++-6

# Download and Install CMake 3.7.2
RUN curl -fsSL "${CMAKE_DOWNLOAD_URL}" -o /tmp/cmake.tar.gz \
    && echo "$CMAKE_SHA256  /tmp/cmake.tar.gz" | sha256sum -c - \
    && tar --directory /tmp -xzf /tmp/cmake.tar.gz \
    && cd /tmp/$CMAKE_DIRECTORY_NAME && ./configure \
    && make && make install \
    && rm -rf /tmp/$CMAKE_FILE_NAME /tmp/cmake.tar.gz

# The variable expansion technique used in this variable definition allows passes arguments
# from the command line and persist them in the final image by leveraging the ENV instruction.
ARG APPLICATION_ENVIRONMENT
ENV APPLICATION_ENVIRONMENT=${APPLICATION_ENVIRONMENT:-development}

# It sets the build-time parameters default values
ARG CMAKE_BUILD_TYPE=Release

# Install the Application
COPY . /tmp/sample
RUN cd /tmp/sample \
    && cmake . \
    && make \
    && cd /tmp/sample && make install \
    && rm -rf /tmp/webservice

# Add the Poco ApacheConnector file configuration file to the image
COPY data/settings/poco.load /etc/apache2/mods-available/poco.load

# Add a script for writing the ENVIRONMENT constant.
COPY scripts/apache-setup-for-dockerfile.sh /tmp/apache-setup-for-dockerfile.sh

RUN chmod +x /tmp/apache-setup-for-dockerfile.sh \
    && /usr/sbin/apache2ctl stop \
    && /tmp/apache-setup-for-dockerfile.sh $APPLICATION_ENVIRONMENT \
    && rm /tmp/apache-setup-for-dockerfile.sh

CMD ["/usr/sbin/apache2ctl", "-DFOREGROUND"]

