
cmake_minimum_required(VERSION 3.16)
project(stonex-cms-amqp-test-cases LANGUAGES CXX)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_STANDARD 20)


file(GLOB sourceFiles ${PROJECT_SOURCE_DIR}/src/Cases/*.cpp)
file(GLOB headerFiles ${PROJECT_SOURCE_DIR}/include/Cases/*.h)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${sourceFiles} ${headerFiles})

add_library(stonex-cms-amqp-tests STATIC
	${sourceFiles} 
	${headerFiles}
	)

target_include_directories(stonex-cms-amqp-tests
	PUBLIC ${PROJECT_SOURCE_DIR}/include
	)

target_link_libraries(stonex-cms-amqp-tests
	CONAN_PKG::stonex-cms-amqp-test-framework
	)



