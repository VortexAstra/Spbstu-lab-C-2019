# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/astra/Desktop/ASTRA/Study/НедоПроги/С++/Лабы 3 сем/B4"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/astra/Desktop/ASTRA/Study/НедоПроги/С++/Лабы 3 сем/B4/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/B4.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/B4.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/B4.dir/flags.make

CMakeFiles/B4.dir/main.cpp.o: CMakeFiles/B4.dir/flags.make
CMakeFiles/B4.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/astra/Desktop/ASTRA/Study/НедоПроги/С++/Лабы 3 сем/B4/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/B4.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/B4.dir/main.cpp.o -c "/Users/astra/Desktop/ASTRA/Study/НедоПроги/С++/Лабы 3 сем/B4/main.cpp"

CMakeFiles/B4.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/B4.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/astra/Desktop/ASTRA/Study/НедоПроги/С++/Лабы 3 сем/B4/main.cpp" > CMakeFiles/B4.dir/main.cpp.i

CMakeFiles/B4.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/B4.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/astra/Desktop/ASTRA/Study/НедоПроги/С++/Лабы 3 сем/B4/main.cpp" -o CMakeFiles/B4.dir/main.cpp.s

# Object files for target B4
B4_OBJECTS = \
"CMakeFiles/B4.dir/main.cpp.o"

# External object files for target B4
B4_EXTERNAL_OBJECTS =

B4: CMakeFiles/B4.dir/main.cpp.o
B4: CMakeFiles/B4.dir/build.make
B4: CMakeFiles/B4.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/astra/Desktop/ASTRA/Study/НедоПроги/С++/Лабы 3 сем/B4/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable B4"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/B4.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/B4.dir/build: B4

.PHONY : CMakeFiles/B4.dir/build

CMakeFiles/B4.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/B4.dir/cmake_clean.cmake
.PHONY : CMakeFiles/B4.dir/clean

CMakeFiles/B4.dir/depend:
	cd "/Users/astra/Desktop/ASTRA/Study/НедоПроги/С++/Лабы 3 сем/B4/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/astra/Desktop/ASTRA/Study/НедоПроги/С++/Лабы 3 сем/B4" "/Users/astra/Desktop/ASTRA/Study/НедоПроги/С++/Лабы 3 сем/B4" "/Users/astra/Desktop/ASTRA/Study/НедоПроги/С++/Лабы 3 сем/B4/cmake-build-debug" "/Users/astra/Desktop/ASTRA/Study/НедоПроги/С++/Лабы 3 сем/B4/cmake-build-debug" "/Users/astra/Desktop/ASTRA/Study/НедоПроги/С++/Лабы 3 сем/B4/cmake-build-debug/CMakeFiles/B4.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/B4.dir/depend

