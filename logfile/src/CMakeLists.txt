set(MKDIR_LIB MKDIR)

add_library(${MKDIR_LIB} STATIC mkdir.cpp)

target_include_directories(${MKDIR_LIB} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})