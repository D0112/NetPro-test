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
CMAKE_SOURCE_DIR = /home/adminn/桌面/project/NetPro-test/logfile

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/adminn/桌面/project/NetPro-test/logfile/build

# Include any dependencies generated for this target.
include src/CMakeFiles/MKDIR.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/MKDIR.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/MKDIR.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/MKDIR.dir/flags.make

src/CMakeFiles/MKDIR.dir/mkdir.cpp.o: src/CMakeFiles/MKDIR.dir/flags.make
src/CMakeFiles/MKDIR.dir/mkdir.cpp.o: ../src/mkdir.cpp
src/CMakeFiles/MKDIR.dir/mkdir.cpp.o: src/CMakeFiles/MKDIR.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adminn/桌面/project/NetPro-test/logfile/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/MKDIR.dir/mkdir.cpp.o"
	cd /home/adminn/桌面/project/NetPro-test/logfile/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/MKDIR.dir/mkdir.cpp.o -MF CMakeFiles/MKDIR.dir/mkdir.cpp.o.d -o CMakeFiles/MKDIR.dir/mkdir.cpp.o -c /home/adminn/桌面/project/NetPro-test/logfile/src/mkdir.cpp

src/CMakeFiles/MKDIR.dir/mkdir.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MKDIR.dir/mkdir.cpp.i"
	cd /home/adminn/桌面/project/NetPro-test/logfile/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adminn/桌面/project/NetPro-test/logfile/src/mkdir.cpp > CMakeFiles/MKDIR.dir/mkdir.cpp.i

src/CMakeFiles/MKDIR.dir/mkdir.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MKDIR.dir/mkdir.cpp.s"
	cd /home/adminn/桌面/project/NetPro-test/logfile/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adminn/桌面/project/NetPro-test/logfile/src/mkdir.cpp -o CMakeFiles/MKDIR.dir/mkdir.cpp.s

# Object files for target MKDIR
MKDIR_OBJECTS = \
"CMakeFiles/MKDIR.dir/mkdir.cpp.o"

# External object files for target MKDIR
MKDIR_EXTERNAL_OBJECTS =

src/libMKDIR.a: src/CMakeFiles/MKDIR.dir/mkdir.cpp.o
src/libMKDIR.a: src/CMakeFiles/MKDIR.dir/build.make
src/libMKDIR.a: src/CMakeFiles/MKDIR.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/adminn/桌面/project/NetPro-test/logfile/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libMKDIR.a"
	cd /home/adminn/桌面/project/NetPro-test/logfile/build/src && $(CMAKE_COMMAND) -P CMakeFiles/MKDIR.dir/cmake_clean_target.cmake
	cd /home/adminn/桌面/project/NetPro-test/logfile/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MKDIR.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/MKDIR.dir/build: src/libMKDIR.a
.PHONY : src/CMakeFiles/MKDIR.dir/build

src/CMakeFiles/MKDIR.dir/clean:
	cd /home/adminn/桌面/project/NetPro-test/logfile/build/src && $(CMAKE_COMMAND) -P CMakeFiles/MKDIR.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/MKDIR.dir/clean

src/CMakeFiles/MKDIR.dir/depend:
	cd /home/adminn/桌面/project/NetPro-test/logfile/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/adminn/桌面/project/NetPro-test/logfile /home/adminn/桌面/project/NetPro-test/logfile/src /home/adminn/桌面/project/NetPro-test/logfile/build /home/adminn/桌面/project/NetPro-test/logfile/build/src /home/adminn/桌面/project/NetPro-test/logfile/build/src/CMakeFiles/MKDIR.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/MKDIR.dir/depend

