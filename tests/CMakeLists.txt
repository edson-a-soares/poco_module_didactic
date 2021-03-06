SET(TESTS_UNIT "tests")

enable_testing()

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

if(NOT GTEST_FOUND)
    message(WARNING "Failed to find the GTest libraries.")
endif()

file(GLOB_RECURSE TESTS_SOURCE_FILES ${CMAKE_HOME_DIRECTORY}/tests/*.cpp)

# It makes the Resources directory path available into the C++ source code as a constant.
add_definitions(-DTESTS_RESOURCES_PATH="${CMAKE_HOME_DIRECTORY}/tests/Resources/")

add_executable(${TESTS_UNIT} ${TESTS_SOURCE_FILES})
target_link_libraries(${TESTS_UNIT} gtest gtest_main pthread ${APPLICATION_BINARY})

add_test(NAME ${TESTS_UNIT} COMMAND ${TESTS_UNIT})
