# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
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
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/shaun/workspace/CPPLearning/week04/exercises/exercise1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/shaun/workspace/CPPLearning/week04/exercises/exercise1/build

# Include any dependencies generated for this target.
include CMakeFiles/stuinfo.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/stuinfo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/stuinfo.dir/flags.make

CMakeFiles/stuinfo.dir/src/main.cpp.o: CMakeFiles/stuinfo.dir/flags.make
CMakeFiles/stuinfo.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shaun/workspace/CPPLearning/week04/exercises/exercise1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/stuinfo.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/stuinfo.dir/src/main.cpp.o -c /home/shaun/workspace/CPPLearning/week04/exercises/exercise1/src/main.cpp

CMakeFiles/stuinfo.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/stuinfo.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shaun/workspace/CPPLearning/week04/exercises/exercise1/src/main.cpp > CMakeFiles/stuinfo.dir/src/main.cpp.i

CMakeFiles/stuinfo.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/stuinfo.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shaun/workspace/CPPLearning/week04/exercises/exercise1/src/main.cpp -o CMakeFiles/stuinfo.dir/src/main.cpp.s

CMakeFiles/stuinfo.dir/src/stuinfo.cpp.o: CMakeFiles/stuinfo.dir/flags.make
CMakeFiles/stuinfo.dir/src/stuinfo.cpp.o: ../src/stuinfo.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shaun/workspace/CPPLearning/week04/exercises/exercise1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/stuinfo.dir/src/stuinfo.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/stuinfo.dir/src/stuinfo.cpp.o -c /home/shaun/workspace/CPPLearning/week04/exercises/exercise1/src/stuinfo.cpp

CMakeFiles/stuinfo.dir/src/stuinfo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/stuinfo.dir/src/stuinfo.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shaun/workspace/CPPLearning/week04/exercises/exercise1/src/stuinfo.cpp > CMakeFiles/stuinfo.dir/src/stuinfo.cpp.i

CMakeFiles/stuinfo.dir/src/stuinfo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/stuinfo.dir/src/stuinfo.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shaun/workspace/CPPLearning/week04/exercises/exercise1/src/stuinfo.cpp -o CMakeFiles/stuinfo.dir/src/stuinfo.cpp.s

# Object files for target stuinfo
stuinfo_OBJECTS = \
"CMakeFiles/stuinfo.dir/src/main.cpp.o" \
"CMakeFiles/stuinfo.dir/src/stuinfo.cpp.o"

# External object files for target stuinfo
stuinfo_EXTERNAL_OBJECTS =

stuinfo: CMakeFiles/stuinfo.dir/src/main.cpp.o
stuinfo: CMakeFiles/stuinfo.dir/src/stuinfo.cpp.o
stuinfo: CMakeFiles/stuinfo.dir/build.make
stuinfo: CMakeFiles/stuinfo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/shaun/workspace/CPPLearning/week04/exercises/exercise1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable stuinfo"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/stuinfo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/stuinfo.dir/build: stuinfo

.PHONY : CMakeFiles/stuinfo.dir/build

CMakeFiles/stuinfo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/stuinfo.dir/cmake_clean.cmake
.PHONY : CMakeFiles/stuinfo.dir/clean

CMakeFiles/stuinfo.dir/depend:
	cd /home/shaun/workspace/CPPLearning/week04/exercises/exercise1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/shaun/workspace/CPPLearning/week04/exercises/exercise1 /home/shaun/workspace/CPPLearning/week04/exercises/exercise1 /home/shaun/workspace/CPPLearning/week04/exercises/exercise1/build /home/shaun/workspace/CPPLearning/week04/exercises/exercise1/build /home/shaun/workspace/CPPLearning/week04/exercises/exercise1/build/CMakeFiles/stuinfo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/stuinfo.dir/depend

