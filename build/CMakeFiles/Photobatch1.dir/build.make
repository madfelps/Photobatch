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
include CMakeFiles/Photobatch1.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Photobatch1.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Photobatch1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Photobatch1.dir/flags.make

CMakeFiles/Photobatch1.dir/Photobatch.cpp.o: CMakeFiles/Photobatch1.dir/flags.make
CMakeFiles/Photobatch1.dir/Photobatch.cpp.o: ../Photobatch.cpp
CMakeFiles/Photobatch1.dir/Photobatch.cpp.o: CMakeFiles/Photobatch1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/felipe/vscodeprojects/Photobatch/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Photobatch1.dir/Photobatch.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Photobatch1.dir/Photobatch.cpp.o -MF CMakeFiles/Photobatch1.dir/Photobatch.cpp.o.d -o CMakeFiles/Photobatch1.dir/Photobatch.cpp.o -c /home/felipe/vscodeprojects/Photobatch/Photobatch.cpp

CMakeFiles/Photobatch1.dir/Photobatch.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Photobatch1.dir/Photobatch.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/felipe/vscodeprojects/Photobatch/Photobatch.cpp > CMakeFiles/Photobatch1.dir/Photobatch.cpp.i

CMakeFiles/Photobatch1.dir/Photobatch.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Photobatch1.dir/Photobatch.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/felipe/vscodeprojects/Photobatch/Photobatch.cpp -o CMakeFiles/Photobatch1.dir/Photobatch.cpp.s

CMakeFiles/Photobatch1.dir/ArgumentParser.cpp.o: CMakeFiles/Photobatch1.dir/flags.make
CMakeFiles/Photobatch1.dir/ArgumentParser.cpp.o: ../ArgumentParser.cpp
CMakeFiles/Photobatch1.dir/ArgumentParser.cpp.o: CMakeFiles/Photobatch1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/felipe/vscodeprojects/Photobatch/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Photobatch1.dir/ArgumentParser.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Photobatch1.dir/ArgumentParser.cpp.o -MF CMakeFiles/Photobatch1.dir/ArgumentParser.cpp.o.d -o CMakeFiles/Photobatch1.dir/ArgumentParser.cpp.o -c /home/felipe/vscodeprojects/Photobatch/ArgumentParser.cpp

CMakeFiles/Photobatch1.dir/ArgumentParser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Photobatch1.dir/ArgumentParser.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/felipe/vscodeprojects/Photobatch/ArgumentParser.cpp > CMakeFiles/Photobatch1.dir/ArgumentParser.cpp.i

CMakeFiles/Photobatch1.dir/ArgumentParser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Photobatch1.dir/ArgumentParser.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/felipe/vscodeprojects/Photobatch/ArgumentParser.cpp -o CMakeFiles/Photobatch1.dir/ArgumentParser.cpp.s

CMakeFiles/Photobatch1.dir/Utils.cpp.o: CMakeFiles/Photobatch1.dir/flags.make
CMakeFiles/Photobatch1.dir/Utils.cpp.o: ../Utils.cpp
CMakeFiles/Photobatch1.dir/Utils.cpp.o: CMakeFiles/Photobatch1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/felipe/vscodeprojects/Photobatch/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Photobatch1.dir/Utils.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Photobatch1.dir/Utils.cpp.o -MF CMakeFiles/Photobatch1.dir/Utils.cpp.o.d -o CMakeFiles/Photobatch1.dir/Utils.cpp.o -c /home/felipe/vscodeprojects/Photobatch/Utils.cpp

CMakeFiles/Photobatch1.dir/Utils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Photobatch1.dir/Utils.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/felipe/vscodeprojects/Photobatch/Utils.cpp > CMakeFiles/Photobatch1.dir/Utils.cpp.i

CMakeFiles/Photobatch1.dir/Utils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Photobatch1.dir/Utils.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/felipe/vscodeprojects/Photobatch/Utils.cpp -o CMakeFiles/Photobatch1.dir/Utils.cpp.s

# Object files for target Photobatch1
Photobatch1_OBJECTS = \
"CMakeFiles/Photobatch1.dir/Photobatch.cpp.o" \
"CMakeFiles/Photobatch1.dir/ArgumentParser.cpp.o" \
"CMakeFiles/Photobatch1.dir/Utils.cpp.o"

# External object files for target Photobatch1
Photobatch1_EXTERNAL_OBJECTS =

Photobatch1: CMakeFiles/Photobatch1.dir/Photobatch.cpp.o
Photobatch1: CMakeFiles/Photobatch1.dir/ArgumentParser.cpp.o
Photobatch1: CMakeFiles/Photobatch1.dir/Utils.cpp.o
Photobatch1: CMakeFiles/Photobatch1.dir/build.make
Photobatch1: CMakeFiles/Photobatch1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/felipe/vscodeprojects/Photobatch/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable Photobatch1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Photobatch1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Photobatch1.dir/build: Photobatch1
.PHONY : CMakeFiles/Photobatch1.dir/build

CMakeFiles/Photobatch1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Photobatch1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Photobatch1.dir/clean

CMakeFiles/Photobatch1.dir/depend:
	cd /home/felipe/vscodeprojects/Photobatch/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/felipe/vscodeprojects/Photobatch /home/felipe/vscodeprojects/Photobatch /home/felipe/vscodeprojects/Photobatch/build /home/felipe/vscodeprojects/Photobatch/build /home/felipe/vscodeprojects/Photobatch/build/CMakeFiles/Photobatch1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Photobatch1.dir/depend

