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
CMAKE_SOURCE_DIR = /mnt/hgfs/sharedUbuntu/nour/sdl2Test/myPong/myPong/tests/mouse_kb

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/hgfs/sharedUbuntu/nour/sdl2Test/myPong/myPong/tests/mouse_kb/build

# Include any dependencies generated for this target.
include CMakeFiles/Sdl2KeyboardMouse.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Sdl2KeyboardMouse.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Sdl2KeyboardMouse.dir/flags.make

CMakeFiles/Sdl2KeyboardMouse.dir/main.cpp.o: CMakeFiles/Sdl2KeyboardMouse.dir/flags.make
CMakeFiles/Sdl2KeyboardMouse.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/hgfs/sharedUbuntu/nour/sdl2Test/myPong/myPong/tests/mouse_kb/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Sdl2KeyboardMouse.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Sdl2KeyboardMouse.dir/main.cpp.o -c /mnt/hgfs/sharedUbuntu/nour/sdl2Test/myPong/myPong/tests/mouse_kb/main.cpp

CMakeFiles/Sdl2KeyboardMouse.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Sdl2KeyboardMouse.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/hgfs/sharedUbuntu/nour/sdl2Test/myPong/myPong/tests/mouse_kb/main.cpp > CMakeFiles/Sdl2KeyboardMouse.dir/main.cpp.i

CMakeFiles/Sdl2KeyboardMouse.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Sdl2KeyboardMouse.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/hgfs/sharedUbuntu/nour/sdl2Test/myPong/myPong/tests/mouse_kb/main.cpp -o CMakeFiles/Sdl2KeyboardMouse.dir/main.cpp.s

# Object files for target Sdl2KeyboardMouse
Sdl2KeyboardMouse_OBJECTS = \
"CMakeFiles/Sdl2KeyboardMouse.dir/main.cpp.o"

# External object files for target Sdl2KeyboardMouse
Sdl2KeyboardMouse_EXTERNAL_OBJECTS =

Sdl2KeyboardMouse: CMakeFiles/Sdl2KeyboardMouse.dir/main.cpp.o
Sdl2KeyboardMouse: CMakeFiles/Sdl2KeyboardMouse.dir/build.make
Sdl2KeyboardMouse: /usr/lib/x86_64-linux-gnu/libSDL2main.a
Sdl2KeyboardMouse: /usr/lib/x86_64-linux-gnu/libSDL2.so
Sdl2KeyboardMouse: /usr/lib/x86_64-linux-gnu/libSDL2_image.so
Sdl2KeyboardMouse: CMakeFiles/Sdl2KeyboardMouse.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/hgfs/sharedUbuntu/nour/sdl2Test/myPong/myPong/tests/mouse_kb/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Sdl2KeyboardMouse"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Sdl2KeyboardMouse.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Sdl2KeyboardMouse.dir/build: Sdl2KeyboardMouse

.PHONY : CMakeFiles/Sdl2KeyboardMouse.dir/build

CMakeFiles/Sdl2KeyboardMouse.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Sdl2KeyboardMouse.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Sdl2KeyboardMouse.dir/clean

CMakeFiles/Sdl2KeyboardMouse.dir/depend:
	cd /mnt/hgfs/sharedUbuntu/nour/sdl2Test/myPong/myPong/tests/mouse_kb/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/hgfs/sharedUbuntu/nour/sdl2Test/myPong/myPong/tests/mouse_kb /mnt/hgfs/sharedUbuntu/nour/sdl2Test/myPong/myPong/tests/mouse_kb /mnt/hgfs/sharedUbuntu/nour/sdl2Test/myPong/myPong/tests/mouse_kb/build /mnt/hgfs/sharedUbuntu/nour/sdl2Test/myPong/myPong/tests/mouse_kb/build /mnt/hgfs/sharedUbuntu/nour/sdl2Test/myPong/myPong/tests/mouse_kb/build/CMakeFiles/Sdl2KeyboardMouse.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Sdl2KeyboardMouse.dir/depend
