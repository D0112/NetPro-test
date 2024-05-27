cmake_minimum_required(VERSION 3.0)

project(CTCPCLIENT)

include_directories(${CMAKE_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/extern)
set(CMAKE_BUILD_TYPE Debug)
set (CMAKE_CXX_FLAGS "${CAMKE_CXX_FLAGS} -finput-charset=UTF-8")
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/extern)
add_executable(ctcpclient main.cpp src/CtcpClient.cpp)
target_link_libraries(ctcpclient libFREECPLUS_SO.so)  