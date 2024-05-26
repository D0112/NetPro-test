cmake_minimum_required(VERSION 3.0)

project(CTCPCLIENT)

#include_directories(${CMAKE_SOURCE_DIR}/include)

#set(CMAKE_BUILD_TYPE Debug)

add_executable(mkdir_cmake main.cpp)

add_subdirectory(src)

target_link_libraries(mkdir_cmake PUBLIC MKDIR)