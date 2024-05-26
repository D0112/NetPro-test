#构建静态库
#set(MKDIR_LIB MKDIR)
#add_library(${MKDIR_LIB} STATIC mkdir.cpp)
#target_include_directories(${MKDIR_LIB} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

#构建动态库
set(MKDIR_LIB MKDIR)

add_library(${MKDIR_LIB} SHARED mkdir.cpp mkdir.h)

#target_include_directories(${MKDIR_LIB} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

#set(MKDIR_DLL ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_BUILD_TYPE}/${MADIR_LIB}.dll)

#add_custom_command(TARGET ${MKDIR_LIB} POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${MKDIR_DLL} ${EXE_DIR})