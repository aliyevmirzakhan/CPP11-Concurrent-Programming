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
CMAKE_COMMAND = /snap/clion/99/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/99/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/mirzakhan/CLionProjects/Multithreading/RaceMutex

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mirzakhan/CLionProjects/Multithreading/RaceMutex/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/RaceMutex.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/RaceMutex.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/RaceMutex.dir/flags.make

CMakeFiles/RaceMutex.dir/main.cpp.o: CMakeFiles/RaceMutex.dir/flags.make
CMakeFiles/RaceMutex.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mirzakhan/CLionProjects/Multithreading/RaceMutex/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/RaceMutex.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RaceMutex.dir/main.cpp.o -c /home/mirzakhan/CLionProjects/Multithreading/RaceMutex/main.cpp

CMakeFiles/RaceMutex.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RaceMutex.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mirzakhan/CLionProjects/Multithreading/RaceMutex/main.cpp > CMakeFiles/RaceMutex.dir/main.cpp.i

CMakeFiles/RaceMutex.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RaceMutex.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mirzakhan/CLionProjects/Multithreading/RaceMutex/main.cpp -o CMakeFiles/RaceMutex.dir/main.cpp.s

# Object files for target RaceMutex
RaceMutex_OBJECTS = \
"CMakeFiles/RaceMutex.dir/main.cpp.o"

# External object files for target RaceMutex
RaceMutex_EXTERNAL_OBJECTS =

RaceMutex: CMakeFiles/RaceMutex.dir/main.cpp.o
RaceMutex: CMakeFiles/RaceMutex.dir/build.make
RaceMutex: CMakeFiles/RaceMutex.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mirzakhan/CLionProjects/Multithreading/RaceMutex/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable RaceMutex"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/RaceMutex.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/RaceMutex.dir/build: RaceMutex

.PHONY : CMakeFiles/RaceMutex.dir/build

CMakeFiles/RaceMutex.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/RaceMutex.dir/cmake_clean.cmake
.PHONY : CMakeFiles/RaceMutex.dir/clean

CMakeFiles/RaceMutex.dir/depend:
	cd /home/mirzakhan/CLionProjects/Multithreading/RaceMutex/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mirzakhan/CLionProjects/Multithreading/RaceMutex /home/mirzakhan/CLionProjects/Multithreading/RaceMutex /home/mirzakhan/CLionProjects/Multithreading/RaceMutex/cmake-build-debug /home/mirzakhan/CLionProjects/Multithreading/RaceMutex/cmake-build-debug /home/mirzakhan/CLionProjects/Multithreading/RaceMutex/cmake-build-debug/CMakeFiles/RaceMutex.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/RaceMutex.dir/depend
