# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/evgenijlebedev/ClionProjects/DZ_5

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/evgenijlebedev/ClionProjects/DZ_5/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/DZ_5.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/DZ_5.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DZ_5.dir/flags.make

CMakeFiles/DZ_5.dir/main.cpp.o: CMakeFiles/DZ_5.dir/flags.make
CMakeFiles/DZ_5.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/evgenijlebedev/ClionProjects/DZ_5/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/DZ_5.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DZ_5.dir/main.cpp.o -c /Users/evgenijlebedev/ClionProjects/DZ_5/main.cpp

CMakeFiles/DZ_5.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DZ_5.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/evgenijlebedev/ClionProjects/DZ_5/main.cpp > CMakeFiles/DZ_5.dir/main.cpp.i

CMakeFiles/DZ_5.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DZ_5.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/evgenijlebedev/ClionProjects/DZ_5/main.cpp -o CMakeFiles/DZ_5.dir/main.cpp.s

CMakeFiles/DZ_5.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/DZ_5.dir/main.cpp.o.requires

CMakeFiles/DZ_5.dir/main.cpp.o.provides: CMakeFiles/DZ_5.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/DZ_5.dir/build.make CMakeFiles/DZ_5.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/DZ_5.dir/main.cpp.o.provides

CMakeFiles/DZ_5.dir/main.cpp.o.provides.build: CMakeFiles/DZ_5.dir/main.cpp.o


# Object files for target DZ_5
DZ_5_OBJECTS = \
"CMakeFiles/DZ_5.dir/main.cpp.o"

# External object files for target DZ_5
DZ_5_EXTERNAL_OBJECTS =

DZ_5: CMakeFiles/DZ_5.dir/main.cpp.o
DZ_5: CMakeFiles/DZ_5.dir/build.make
DZ_5: CMakeFiles/DZ_5.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/evgenijlebedev/ClionProjects/DZ_5/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable DZ_5"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/DZ_5.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DZ_5.dir/build: DZ_5

.PHONY : CMakeFiles/DZ_5.dir/build

CMakeFiles/DZ_5.dir/requires: CMakeFiles/DZ_5.dir/main.cpp.o.requires

.PHONY : CMakeFiles/DZ_5.dir/requires

CMakeFiles/DZ_5.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/DZ_5.dir/cmake_clean.cmake
.PHONY : CMakeFiles/DZ_5.dir/clean

CMakeFiles/DZ_5.dir/depend:
	cd /Users/evgenijlebedev/ClionProjects/DZ_5/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/evgenijlebedev/ClionProjects/DZ_5 /Users/evgenijlebedev/ClionProjects/DZ_5 /Users/evgenijlebedev/ClionProjects/DZ_5/cmake-build-debug /Users/evgenijlebedev/ClionProjects/DZ_5/cmake-build-debug /Users/evgenijlebedev/ClionProjects/DZ_5/cmake-build-debug/CMakeFiles/DZ_5.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/DZ_5.dir/depend
