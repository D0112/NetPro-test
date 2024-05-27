cmake_minimum_required(VERSION 3.0)

project(CTCPCLIENT)

#include_directories(${CMAKE_SOURCE_DIR}/include)

#set(CMAKE_BUILD_TYPE Debug)

#构建静态库
#add_executable(mkdir_cmake main.cpp)

#add_subdirectory(src)

#target_link_libraries(mkdir_cmake PUBLIC MKDIR)

#构建动态库
#set(EXE_DIR ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_BUILD_TYPE})
#make_directory(${EXE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/extern)
set(CMAKE_BUILD_TYPE Debug)
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/extern)
add_executable(mkdir_cmake main.cpp)
target_link_libraries(mkdir_cmake libFREECPLUS_SO.so)