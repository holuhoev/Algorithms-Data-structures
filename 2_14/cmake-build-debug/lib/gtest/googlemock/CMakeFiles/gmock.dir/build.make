# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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
CMAKE_SOURCE_DIR = /Users/evgenijlebedev/ClionProjects/2_14

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/evgenijlebedev/ClionProjects/2_14/cmake-build-debug

# Include any dependencies generated for this target.
include lib/gtest/googlemock/CMakeFiles/gmock.dir/depend.make

# Include the progress variables for this target.
include lib/gtest/googlemock/CMakeFiles/gmock.dir/progress.make

# Include the compile flags for this target's objects.
include lib/gtest/googlemock/CMakeFiles/gmock.dir/flags.make

lib/gtest/googlemock/CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.o: lib/gtest/googlemock/CMakeFiles/gmock.dir/flags.make
lib/gtest/googlemock/CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.o: ../lib/gtest/googletest/src/gtest-all.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/evgenijlebedev/ClionProjects/2_14/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/gtest/googlemock/CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.o"
	cd /Users/evgenijlebedev/ClionProjects/2_14/cmake-build-debug/lib/gtest/googlemock && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.o -c /Users/evgenijlebedev/ClionProjects/2_14/lib/gtest/googletest/src/gtest-all.cc

lib/gtest/googlemock/CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.i"
	cd /Users/evgenijlebedev/ClionProjects/2_14/cmake-build-debug/lib/gtest/googlemock && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/evgenijlebedev/ClionProjects/2_14/lib/gtest/googletest/src/gtest-all.cc > CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.i

lib/gtest/googlemock/CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.s"
	cd /Users/evgenijlebedev/ClionProjects/2_14/cmake-build-debug/lib/gtest/googlemock && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/evgenijlebedev/ClionProjects/2_14/lib/gtest/googletest/src/gtest-all.cc -o CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.s

lib/gtest/googlemock/CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.o.requires:

.PHONY : lib/gtest/googlemock/CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.o.requires

lib/gtest/googlemock/CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.o.provides: lib/gtest/googlemock/CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.o.requires
	$(MAKE) -f lib/gtest/googlemock/CMakeFiles/gmock.dir/build.make lib/gtest/googlemock/CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.o.provides.build
.PHONY : lib/gtest/googlemock/CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.o.provides

lib/gtest/googlemock/CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.o.provides.build: lib/gtest/googlemock/CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.o


lib/gtest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o: lib/gtest/googlemock/CMakeFiles/gmock.dir/flags.make
lib/gtest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o: ../lib/gtest/googlemock/src/gmock-all.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/evgenijlebedev/ClionProjects/2_14/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object lib/gtest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o"
	cd /Users/evgenijlebedev/ClionProjects/2_14/cmake-build-debug/lib/gtest/googlemock && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gmock.dir/src/gmock-all.cc.o -c /Users/evgenijlebedev/ClionProjects/2_14/lib/gtest/googlemock/src/gmock-all.cc

lib/gtest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gmock.dir/src/gmock-all.cc.i"
	cd /Users/evgenijlebedev/ClionProjects/2_14/cmake-build-debug/lib/gtest/googlemock && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/evgenijlebedev/ClionProjects/2_14/lib/gtest/googlemock/src/gmock-all.cc > CMakeFiles/gmock.dir/src/gmock-all.cc.i

lib/gtest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gmock.dir/src/gmock-all.cc.s"
	cd /Users/evgenijlebedev/ClionProjects/2_14/cmake-build-debug/lib/gtest/googlemock && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/evgenijlebedev/ClionProjects/2_14/lib/gtest/googlemock/src/gmock-all.cc -o CMakeFiles/gmock.dir/src/gmock-all.cc.s

lib/gtest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o.requires:

.PHONY : lib/gtest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o.requires

lib/gtest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o.provides: lib/gtest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o.requires
	$(MAKE) -f lib/gtest/googlemock/CMakeFiles/gmock.dir/build.make lib/gtest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o.provides.build
.PHONY : lib/gtest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o.provides

lib/gtest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o.provides.build: lib/gtest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o


# Object files for target gmock
gmock_OBJECTS = \
"CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.o" \
"CMakeFiles/gmock.dir/src/gmock-all.cc.o"

# External object files for target gmock
gmock_EXTERNAL_OBJECTS =

lib/gtest/googlemock/libgmock.a: lib/gtest/googlemock/CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.o
lib/gtest/googlemock/libgmock.a: lib/gtest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o
lib/gtest/googlemock/libgmock.a: lib/gtest/googlemock/CMakeFiles/gmock.dir/build.make
lib/gtest/googlemock/libgmock.a: lib/gtest/googlemock/CMakeFiles/gmock.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/evgenijlebedev/ClionProjects/2_14/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libgmock.a"
	cd /Users/evgenijlebedev/ClionProjects/2_14/cmake-build-debug/lib/gtest/googlemock && $(CMAKE_COMMAND) -P CMakeFiles/gmock.dir/cmake_clean_target.cmake
	cd /Users/evgenijlebedev/ClionProjects/2_14/cmake-build-debug/lib/gtest/googlemock && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gmock.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/gtest/googlemock/CMakeFiles/gmock.dir/build: lib/gtest/googlemock/libgmock.a

.PHONY : lib/gtest/googlemock/CMakeFiles/gmock.dir/build

lib/gtest/googlemock/CMakeFiles/gmock.dir/requires: lib/gtest/googlemock/CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.o.requires
lib/gtest/googlemock/CMakeFiles/gmock.dir/requires: lib/gtest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o.requires

.PHONY : lib/gtest/googlemock/CMakeFiles/gmock.dir/requires

lib/gtest/googlemock/CMakeFiles/gmock.dir/clean:
	cd /Users/evgenijlebedev/ClionProjects/2_14/cmake-build-debug/lib/gtest/googlemock && $(CMAKE_COMMAND) -P CMakeFiles/gmock.dir/cmake_clean.cmake
.PHONY : lib/gtest/googlemock/CMakeFiles/gmock.dir/clean

lib/gtest/googlemock/CMakeFiles/gmock.dir/depend:
	cd /Users/evgenijlebedev/ClionProjects/2_14/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/evgenijlebedev/ClionProjects/2_14 /Users/evgenijlebedev/ClionProjects/2_14/lib/gtest/googlemock /Users/evgenijlebedev/ClionProjects/2_14/cmake-build-debug /Users/evgenijlebedev/ClionProjects/2_14/cmake-build-debug/lib/gtest/googlemock /Users/evgenijlebedev/ClionProjects/2_14/cmake-build-debug/lib/gtest/googlemock/CMakeFiles/gmock.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/gtest/googlemock/CMakeFiles/gmock.dir/depend

