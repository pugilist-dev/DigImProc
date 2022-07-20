# Set project name
project(image_read_write)

#minimum version of the cmake required
cmake_minimum_required(VERSION 3.1)

set (CMAKE_CXX_STANDARD 11)
if(NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS "-Wall -Wextra -fPIC")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-o3")

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

message(STATUS "This Shit just works")

include_directories(${PROJECT_SOURCE_DIR}/src)

#add the src sub directory
add_subdirectory(${PROJECT_SOURCE_DIR}/src)
