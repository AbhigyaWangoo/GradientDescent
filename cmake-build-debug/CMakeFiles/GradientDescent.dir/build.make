# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/abhiwangoo/Desktop/GradientDescent

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/abhiwangoo/Desktop/GradientDescent/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/GradientDescent.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/GradientDescent.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/GradientDescent.dir/flags.make

CMakeFiles/GradientDescent.dir/sample.cpp.o: CMakeFiles/GradientDescent.dir/flags.make
CMakeFiles/GradientDescent.dir/sample.cpp.o: ../sample.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/abhiwangoo/Desktop/GradientDescent/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/GradientDescent.dir/sample.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GradientDescent.dir/sample.cpp.o -c /Users/abhiwangoo/Desktop/GradientDescent/sample.cpp

CMakeFiles/GradientDescent.dir/sample.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GradientDescent.dir/sample.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/abhiwangoo/Desktop/GradientDescent/sample.cpp > CMakeFiles/GradientDescent.dir/sample.cpp.i

CMakeFiles/GradientDescent.dir/sample.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GradientDescent.dir/sample.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/abhiwangoo/Desktop/GradientDescent/sample.cpp -o CMakeFiles/GradientDescent.dir/sample.cpp.s

# Object files for target GradientDescent
GradientDescent_OBJECTS = \
"CMakeFiles/GradientDescent.dir/sample.cpp.o"

# External object files for target GradientDescent
GradientDescent_EXTERNAL_OBJECTS =

GradientDescent: CMakeFiles/GradientDescent.dir/sample.cpp.o
GradientDescent: CMakeFiles/GradientDescent.dir/build.make
GradientDescent: CMakeFiles/GradientDescent.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/abhiwangoo/Desktop/GradientDescent/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable GradientDescent"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/GradientDescent.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/GradientDescent.dir/build: GradientDescent

.PHONY : CMakeFiles/GradientDescent.dir/build

CMakeFiles/GradientDescent.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/GradientDescent.dir/cmake_clean.cmake
.PHONY : CMakeFiles/GradientDescent.dir/clean

CMakeFiles/GradientDescent.dir/depend:
	cd /Users/abhiwangoo/Desktop/GradientDescent/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/abhiwangoo/Desktop/GradientDescent /Users/abhiwangoo/Desktop/GradientDescent /Users/abhiwangoo/Desktop/GradientDescent/cmake-build-debug /Users/abhiwangoo/Desktop/GradientDescent/cmake-build-debug /Users/abhiwangoo/Desktop/GradientDescent/cmake-build-debug/CMakeFiles/GradientDescent.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/GradientDescent.dir/depend

