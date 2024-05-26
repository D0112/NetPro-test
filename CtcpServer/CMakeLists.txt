cmake_minimum_required(VERSION 3.0)

project(CTCPSERVER)

include_directories(${CMAKE_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/mkdir/include)
set(CMAKE_BUILD_TYPE Debug)
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/mkdir)
add_executable(ctcpserver main.cpp src/CtcpServe.cpp)
target_link_libraries(ctcpserver libMKDIR.so)  