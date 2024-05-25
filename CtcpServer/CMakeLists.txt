cmake_minimum_required(VERSION 3.0)

project(CTCPSERVER)

include_directories(${CMAKE_SOURCE_DIR}/include)
set(CMAKE_BUILD_TYPE Debug)
add_executable(ctcpserver main.cpp src/CtcpServe.cpp)