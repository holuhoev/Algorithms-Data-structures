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
CMAKE_SOURCE_DIR = /Users/evgenijlebedev/ClionProjects/kmh

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/evgenijlebedev/ClionProjects/kmh/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/kmh.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/kmh.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/kmh.dir/flags.make

CMakeFiles/kmh.dir/main.cpp.o: CMakeFiles/kmh.dir/flags.make
CMakeFiles/kmh.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/evgenijlebedev/ClionProjects/kmh/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/kmh.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/kmh.dir/main.cpp.o -c /Users/evgenijlebedev/ClionProjects/kmh/main.cpp

CMakeFiles/kmh.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/kmh.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/evgenijlebedev/ClionProjects/kmh/main.cpp > CMakeFiles/kmh.dir/main.cpp.i

CMakeFiles/kmh.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/kmh.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/evgenijlebedev/ClionProjects/kmh/main.cpp -o CMakeFiles/kmh.dir/main.cpp.s

CMakeFiles/kmh.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/kmh.dir/main.cpp.o.requires

CMakeFiles/kmh.dir/main.cpp.o.provides: CMakeFiles/kmh.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/kmh.dir/build.make CMakeFiles/kmh.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/kmh.dir/main.cpp.o.provides

CMakeFiles/kmh.dir/main.cpp.o.provides.build: CMakeFiles/kmh.dir/main.cpp.o


CMakeFiles/kmh.dir/kmp.cpp.o: CMakeFiles/kmh.dir/flags.make
CMakeFiles/kmh.dir/kmp.cpp.o: ../kmp.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/evgenijlebedev/ClionProjects/kmh/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/kmh.dir/kmp.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/kmh.dir/kmp.cpp.o -c /Users/evgenijlebedev/ClionProjects/kmh/kmp.cpp

CMakeFiles/kmh.dir/kmp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/kmh.dir/kmp.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/evgenijlebedev/ClionProjects/kmh/kmp.cpp > CMakeFiles/kmh.dir/kmp.cpp.i

CMakeFiles/kmh.dir/kmp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/kmh.dir/kmp.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/evgenijlebedev/ClionProjects/kmh/kmp.cpp -o CMakeFiles/kmh.dir/kmp.cpp.s

CMakeFiles/kmh.dir/kmp.cpp.o.requires:

.PHONY : CMakeFiles/kmh.dir/kmp.cpp.o.requires

CMakeFiles/kmh.dir/kmp.cpp.o.provides: CMakeFiles/kmh.dir/kmp.cpp.o.requires
	$(MAKE) -f CMakeFiles/kmh.dir/build.make CMakeFiles/kmh.dir/kmp.cpp.o.provides.build
.PHONY : CMakeFiles/kmh.dir/kmp.cpp.o.provides

CMakeFiles/kmh.dir/kmp.cpp.o.provides.build: CMakeFiles/kmh.dir/kmp.cpp.o


# Object files for target kmh
kmh_OBJECTS = \
"CMakeFiles/kmh.dir/main.cpp.o" \
"CMakeFiles/kmh.dir/kmp.cpp.o"

# External object files for target kmh
kmh_EXTERNAL_OBJECTS =

kmh: CMakeFiles/kmh.dir/main.cpp.o
kmh: CMakeFiles/kmh.dir/kmp.cpp.o
kmh: CMakeFiles/kmh.dir/build.make
kmh: CMakeFiles/kmh.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/evgenijlebedev/ClionProjects/kmh/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable kmh"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/kmh.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/kmh.dir/build: kmh

.PHONY : CMakeFiles/kmh.dir/build

CMakeFiles/kmh.dir/requires: CMakeFiles/kmh.dir/main.cpp.o.requires
CMakeFiles/kmh.dir/requires: CMakeFiles/kmh.dir/kmp.cpp.o.requires

.PHONY : CMakeFiles/kmh.dir/requires

CMakeFiles/kmh.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/kmh.dir/cmake_clean.cmake
.PHONY : CMakeFiles/kmh.dir/clean

CMakeFiles/kmh.dir/depend:
	cd /Users/evgenijlebedev/ClionProjects/kmh/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/evgenijlebedev/ClionProjects/kmh /Users/evgenijlebedev/ClionProjects/kmh /Users/evgenijlebedev/ClionProjects/kmh/cmake-build-debug /Users/evgenijlebedev/ClionProjects/kmh/cmake-build-debug /Users/evgenijlebedev/ClionProjects/kmh/cmake-build-debug/CMakeFiles/kmh.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/kmh.dir/depend

