# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/adminn/桌面/project/NetPro-test/CtcpServer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/adminn/桌面/project/NetPro-test/CtcpServer/build

# Include any dependencies generated for this target.
include CMakeFiles/ctcpserver.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/ctcpserver.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ctcpserver.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ctcpserver.dir/flags.make

CMakeFiles/ctcpserver.dir/main.cpp.o: CMakeFiles/ctcpserver.dir/flags.make
CMakeFiles/ctcpserver.dir/main.cpp.o: ../main.cpp
CMakeFiles/ctcpserver.dir/main.cpp.o: CMakeFiles/ctcpserver.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adminn/桌面/project/NetPro-test/CtcpServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ctcpserver.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ctcpserver.dir/main.cpp.o -MF CMakeFiles/ctcpserver.dir/main.cpp.o.d -o CMakeFiles/ctcpserver.dir/main.cpp.o -c /home/adminn/桌面/project/NetPro-test/CtcpServer/main.cpp

CMakeFiles/ctcpserver.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ctcpserver.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adminn/桌面/project/NetPro-test/CtcpServer/main.cpp > CMakeFiles/ctcpserver.dir/main.cpp.i

CMakeFiles/ctcpserver.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ctcpserver.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adminn/桌面/project/NetPro-test/CtcpServer/main.cpp -o CMakeFiles/ctcpserver.dir/main.cpp.s

CMakeFiles/ctcpserver.dir/src/CtcpServe.cpp.o: CMakeFiles/ctcpserver.dir/flags.make
CMakeFiles/ctcpserver.dir/src/CtcpServe.cpp.o: ../src/CtcpServe.cpp
CMakeFiles/ctcpserver.dir/src/CtcpServe.cpp.o: CMakeFiles/ctcpserver.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adminn/桌面/project/NetPro-test/CtcpServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ctcpserver.dir/src/CtcpServe.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ctcpserver.dir/src/CtcpServe.cpp.o -MF CMakeFiles/ctcpserver.dir/src/CtcpServe.cpp.o.d -o CMakeFiles/ctcpserver.dir/src/CtcpServe.cpp.o -c /home/adminn/桌面/project/NetPro-test/CtcpServer/src/CtcpServe.cpp

CMakeFiles/ctcpserver.dir/src/CtcpServe.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ctcpserver.dir/src/CtcpServe.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adminn/桌面/project/NetPro-test/CtcpServer/src/CtcpServe.cpp > CMakeFiles/ctcpserver.dir/src/CtcpServe.cpp.i

CMakeFiles/ctcpserver.dir/src/CtcpServe.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ctcpserver.dir/src/CtcpServe.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adminn/桌面/project/NetPro-test/CtcpServer/src/CtcpServe.cpp -o CMakeFiles/ctcpserver.dir/src/CtcpServe.cpp.s

# Object files for target ctcpserver
ctcpserver_OBJECTS = \
"CMakeFiles/ctcpserver.dir/main.cpp.o" \
"CMakeFiles/ctcpserver.dir/src/CtcpServe.cpp.o"

# External object files for target ctcpserver
ctcpserver_EXTERNAL_OBJECTS =

ctcpserver: CMakeFiles/ctcpserver.dir/main.cpp.o
ctcpserver: CMakeFiles/ctcpserver.dir/src/CtcpServe.cpp.o
ctcpserver: CMakeFiles/ctcpserver.dir/build.make
ctcpserver: CMakeFiles/ctcpserver.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/adminn/桌面/project/NetPro-test/CtcpServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ctcpserver"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ctcpserver.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ctcpserver.dir/build: ctcpserver
.PHONY : CMakeFiles/ctcpserver.dir/build

CMakeFiles/ctcpserver.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ctcpserver.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ctcpserver.dir/clean

CMakeFiles/ctcpserver.dir/depend:
	cd /home/adminn/桌面/project/NetPro-test/CtcpServer/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/adminn/桌面/project/NetPro-test/CtcpServer /home/adminn/桌面/project/NetPro-test/CtcpServer /home/adminn/桌面/project/NetPro-test/CtcpServer/build /home/adminn/桌面/project/NetPro-test/CtcpServer/build /home/adminn/桌面/project/NetPro-test/CtcpServer/build/CMakeFiles/ctcpserver.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ctcpserver.dir/depend

