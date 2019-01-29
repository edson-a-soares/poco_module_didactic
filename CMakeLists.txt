cmake_minimum_required(VERSION 3.7)

set(CMAKE_C_COMPILER /usr/bin/gcc)
set(CMAKE_CXX_COMPILER /usr/bin/g++)

# It sets default as Release build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release")
    message(STATUS "CMake Build Type: ${CMAKE_BUILD_TYPE}")
else()
    message(STATUS "CMake Build Type: ${CMAKE_BUILD_TYPE}")
endif()


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wextra -Wall -Wpedantic")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} \
        -fprofile-arcs -ftest-coverage \
        -g -O0 -rdynamic -Wshadow -Wunused-parameter -Wunused-variable -Wdelete-non-virtual-dtor -Wfatal-errors \
        -Woverloaded-virtual -Wunreachable-code -Wno-unused -Wundef -Wl,--no-undefined -Wl,--no-allow-shlib-undefined")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3 -w -Wl,--discard-all")


# It removes the prefix "lib" from the .so file of the application
set(CMAKE_SHARED_LIBRARY_PREFIX "")

# Application's binary name
set(APPLICATION_BINARY apache_application)

# Target directory for the main file of the application
SET(APPLICATION_EXECUTABLE_DIRECTORY "/usr/local/bin")

# Application's Command Line executable name
set(APPLICATION_STANDALONE_EXECUTABLE standalone_launcher)

# Other application binary's files hosting directory
SET(APPLICATION_HOSTING_DIRECTORY "/usr/local/lib/")


find_library(POCO_NET PocoNet)
find_library(POCO_JSON PocoJSON)
find_library(POCO_UTIL PocoUtil)
find_library(POCO_FOUNDATION PocoFoundation)
include_directories(${Poco_INCLUDE_DIRS})

find_package(Threads REQUIRED)


# Includes source code
set(PROJECT_INCLUDE_DIR ${CMAKE_HOME_DIRECTORY}/include)
set(PROJECT_SOURCE_DIR ${CMAKE_HOME_DIRECTORY}/src)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/bin)

file(GLOB_RECURSE SOURCE_FILES ${PROJECT_SOURCE_DIR}/Application/*.cpp)

include_directories("${PROJECT_INCLUDE_DIR}")
include_directories("${PROJECT_SOURCE_DIR}")

add_library(${APPLICATION_BINARY} SHARED ${SOURCE_FILES})
target_link_libraries(${APPLICATION_BINARY} ${POCO_FOUNDATION} ${POCO_UTIL} ${POCO_JSON} ${POCO_NET})
target_include_directories(${APPLICATION_BINARY} PUBLIC ${PROJECT_INCLUDE_DIR})


#### handling options ########################################

option(ENABLE_TESTS
        "Set to OFF|ON (default: OFF) to control build of Application tests" OFF)

option(ENABLE_STANDALONE_EXECUTABLE
        "Set to OFF|ON (default: ON) to control build of Standalone Executable" ON)

if (ENABLE_STANDALONE_EXECUTABLE)
    add_executable(${APPLICATION_STANDALONE_EXECUTABLE} ${PROJECT_SOURCE_DIR}/main.cpp)
    target_link_libraries(${APPLICATION_STANDALONE_EXECUTABLE} ${APPLICATION_BINARY})

    message(STATUS "Building with Standalone Executable")
elseif ()
    message(STATUS "Building without Standalone Executable")
endif ()

if (ENABLE_TESTS)
    # add_subdirectory(tests)

    message(STATUS "Building with tests")
elseif ()
    message(STATUS "Building without tests")
endif ()


# Install application
install(TARGETS ${APPLICATION_BINARY} DESTINATION ${APPLICATION_HOSTING_DIRECTORY})
# install(TARGETS ${APPLICATION_STANDALONE_EXECUTABLE} DESTINATION ${APPLICATION_EXECUTABLE_DIRECTORY} OPTIONAL)
