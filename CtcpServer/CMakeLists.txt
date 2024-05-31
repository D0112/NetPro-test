cmake_minimum_required(VERSION 3.0)

project(CTCPSERVER)

include_directories(${CMAKE_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/extern)
set(CMAKE_BUILD_TYPE Debug)
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/extern pthread)
add_executable(ctcpserver main.cpp src/CtcpServe.cpp extern/TaskQueue.cpp extern/ThreadPool.cpp)
target_link_libraries(ctcpserver libFREECPLUS_SO.so)  