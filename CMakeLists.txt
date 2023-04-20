
cmake_minimum_required(VERSION 3.16)
project(stonex-cms-amqp-test-cases LANGUAGES CXX)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_STANDARD 20)

add_subdirectory(CoreTests)