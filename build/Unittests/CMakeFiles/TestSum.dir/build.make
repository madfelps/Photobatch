# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

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
CMAKE_COMMAND = /snap/cmake/1082/bin/cmake

# The command to remove a file.
RM = /snap/cmake/1082/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/felipe/vscodeprojects/Photobatch

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/felipe/vscodeprojects/Photobatch/build

# Include any dependencies generated for this target.
include Unittests/CMakeFiles/TestSum.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include Unittests/CMakeFiles/TestSum.dir/compiler_depend.make

# Include the progress variables for this target.
include Unittests/CMakeFiles/TestSum.dir/progress.make

# Include the compile flags for this target's objects.
include Unittests/CMakeFiles/TestSum.dir/flags.make

Unittests/CMakeFiles/TestSum.dir/TestArgumentParser.cpp.o: Unittests/CMakeFiles/TestSum.dir/flags.make
Unittests/CMakeFiles/TestSum.dir/TestArgumentParser.cpp.o: ../Unittests/TestArgumentParser.cpp
Unittests/CMakeFiles/TestSum.dir/TestArgumentParser.cpp.o: Unittests/CMakeFiles/TestSum.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/felipe/vscodeprojects/Photobatch/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Unittests/CMakeFiles/TestSum.dir/TestArgumentParser.cpp.o"
	cd /home/felipe/vscodeprojects/Photobatch/build/Unittests && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Unittests/CMakeFiles/TestSum.dir/TestArgumentParser.cpp.o -MF CMakeFiles/TestSum.dir/TestArgumentParser.cpp.o.d -o CMakeFiles/TestSum.dir/TestArgumentParser.cpp.o -c /home/felipe/vscodeprojects/Photobatch/Unittests/TestArgumentParser.cpp

Unittests/CMakeFiles/TestSum.dir/TestArgumentParser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TestSum.dir/TestArgumentParser.cpp.i"
	cd /home/felipe/vscodeprojects/Photobatch/build/Unittests && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/felipe/vscodeprojects/Photobatch/Unittests/TestArgumentParser.cpp > CMakeFiles/TestSum.dir/TestArgumentParser.cpp.i

Unittests/CMakeFiles/TestSum.dir/TestArgumentParser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TestSum.dir/TestArgumentParser.cpp.s"
	cd /home/felipe/vscodeprojects/Photobatch/build/Unittests && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/felipe/vscodeprojects/Photobatch/Unittests/TestArgumentParser.cpp -o CMakeFiles/TestSum.dir/TestArgumentParser.cpp.s

# Object files for target TestSum
TestSum_OBJECTS = \
"CMakeFiles/TestSum.dir/TestArgumentParser.cpp.o"

# External object files for target TestSum
TestSum_EXTERNAL_OBJECTS =

Unittests/TestSum: Unittests/CMakeFiles/TestSum.dir/TestArgumentParser.cpp.o
Unittests/TestSum: Unittests/CMakeFiles/TestSum.dir/build.make
Unittests/TestSum: lib/libgtest_maind.a
Unittests/TestSum: lib/libgtestd.a
Unittests/TestSum: Unittests/CMakeFiles/TestSum.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/felipe/vscodeprojects/Photobatch/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TestSum"
	cd /home/felipe/vscodeprojects/Photobatch/build/Unittests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TestSum.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Unittests/CMakeFiles/TestSum.dir/build: Unittests/TestSum
.PHONY : Unittests/CMakeFiles/TestSum.dir/build

Unittests/CMakeFiles/TestSum.dir/clean:
	cd /home/felipe/vscodeprojects/Photobatch/build/Unittests && $(CMAKE_COMMAND) -P CMakeFiles/TestSum.dir/cmake_clean.cmake
.PHONY : Unittests/CMakeFiles/TestSum.dir/clean

Unittests/CMakeFiles/TestSum.dir/depend:
	cd /home/felipe/vscodeprojects/Photobatch/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/felipe/vscodeprojects/Photobatch /home/felipe/vscodeprojects/Photobatch/Unittests /home/felipe/vscodeprojects/Photobatch/build /home/felipe/vscodeprojects/Photobatch/build/Unittests /home/felipe/vscodeprojects/Photobatch/build/Unittests/CMakeFiles/TestSum.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Unittests/CMakeFiles/TestSum.dir/depend

