# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /snap/clion/61/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/61/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/andreivoiculas/OpenGL

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/andreivoiculas/OpenGL

# Include any dependencies generated for this target.
include CMakeFiles/OpenGL.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/OpenGL.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/OpenGL.dir/flags.make

CMakeFiles/OpenGL.dir/src/main.cpp.o: CMakeFiles/OpenGL.dir/flags.make
CMakeFiles/OpenGL.dir/src/main.cpp.o: src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andreivoiculas/OpenGL/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/OpenGL.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OpenGL.dir/src/main.cpp.o -c /home/andreivoiculas/OpenGL/src/main.cpp

CMakeFiles/OpenGL.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OpenGL.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/andreivoiculas/OpenGL/src/main.cpp > CMakeFiles/OpenGL.dir/src/main.cpp.i

CMakeFiles/OpenGL.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OpenGL.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/andreivoiculas/OpenGL/src/main.cpp -o CMakeFiles/OpenGL.dir/src/main.cpp.s

CMakeFiles/OpenGL.dir/src/Camera.cpp.o: CMakeFiles/OpenGL.dir/flags.make
CMakeFiles/OpenGL.dir/src/Camera.cpp.o: src/Camera.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andreivoiculas/OpenGL/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/OpenGL.dir/src/Camera.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OpenGL.dir/src/Camera.cpp.o -c /home/andreivoiculas/OpenGL/src/Camera.cpp

CMakeFiles/OpenGL.dir/src/Camera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OpenGL.dir/src/Camera.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/andreivoiculas/OpenGL/src/Camera.cpp > CMakeFiles/OpenGL.dir/src/Camera.cpp.i

CMakeFiles/OpenGL.dir/src/Camera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OpenGL.dir/src/Camera.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/andreivoiculas/OpenGL/src/Camera.cpp -o CMakeFiles/OpenGL.dir/src/Camera.cpp.s

CMakeFiles/OpenGL.dir/src/Shader.cpp.o: CMakeFiles/OpenGL.dir/flags.make
CMakeFiles/OpenGL.dir/src/Shader.cpp.o: src/Shader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andreivoiculas/OpenGL/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/OpenGL.dir/src/Shader.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OpenGL.dir/src/Shader.cpp.o -c /home/andreivoiculas/OpenGL/src/Shader.cpp

CMakeFiles/OpenGL.dir/src/Shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OpenGL.dir/src/Shader.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/andreivoiculas/OpenGL/src/Shader.cpp > CMakeFiles/OpenGL.dir/src/Shader.cpp.i

CMakeFiles/OpenGL.dir/src/Shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OpenGL.dir/src/Shader.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/andreivoiculas/OpenGL/src/Shader.cpp -o CMakeFiles/OpenGL.dir/src/Shader.cpp.s

CMakeFiles/OpenGL.dir/src/Program.cpp.o: CMakeFiles/OpenGL.dir/flags.make
CMakeFiles/OpenGL.dir/src/Program.cpp.o: src/Program.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andreivoiculas/OpenGL/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/OpenGL.dir/src/Program.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OpenGL.dir/src/Program.cpp.o -c /home/andreivoiculas/OpenGL/src/Program.cpp

CMakeFiles/OpenGL.dir/src/Program.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OpenGL.dir/src/Program.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/andreivoiculas/OpenGL/src/Program.cpp > CMakeFiles/OpenGL.dir/src/Program.cpp.i

CMakeFiles/OpenGL.dir/src/Program.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OpenGL.dir/src/Program.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/andreivoiculas/OpenGL/src/Program.cpp -o CMakeFiles/OpenGL.dir/src/Program.cpp.s

CMakeFiles/OpenGL.dir/src/Shape.cpp.o: CMakeFiles/OpenGL.dir/flags.make
CMakeFiles/OpenGL.dir/src/Shape.cpp.o: src/Shape.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andreivoiculas/OpenGL/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/OpenGL.dir/src/Shape.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OpenGL.dir/src/Shape.cpp.o -c /home/andreivoiculas/OpenGL/src/Shape.cpp

CMakeFiles/OpenGL.dir/src/Shape.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OpenGL.dir/src/Shape.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/andreivoiculas/OpenGL/src/Shape.cpp > CMakeFiles/OpenGL.dir/src/Shape.cpp.i

CMakeFiles/OpenGL.dir/src/Shape.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OpenGL.dir/src/Shape.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/andreivoiculas/OpenGL/src/Shape.cpp -o CMakeFiles/OpenGL.dir/src/Shape.cpp.s

CMakeFiles/OpenGL.dir/src/MovingShape.cpp.o: CMakeFiles/OpenGL.dir/flags.make
CMakeFiles/OpenGL.dir/src/MovingShape.cpp.o: src/MovingShape.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andreivoiculas/OpenGL/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/OpenGL.dir/src/MovingShape.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OpenGL.dir/src/MovingShape.cpp.o -c /home/andreivoiculas/OpenGL/src/MovingShape.cpp

CMakeFiles/OpenGL.dir/src/MovingShape.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OpenGL.dir/src/MovingShape.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/andreivoiculas/OpenGL/src/MovingShape.cpp > CMakeFiles/OpenGL.dir/src/MovingShape.cpp.i

CMakeFiles/OpenGL.dir/src/MovingShape.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OpenGL.dir/src/MovingShape.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/andreivoiculas/OpenGL/src/MovingShape.cpp -o CMakeFiles/OpenGL.dir/src/MovingShape.cpp.s

CMakeFiles/OpenGL.dir/src/Particles.cpp.o: CMakeFiles/OpenGL.dir/flags.make
CMakeFiles/OpenGL.dir/src/Particles.cpp.o: src/Particles.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andreivoiculas/OpenGL/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/OpenGL.dir/src/Particles.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OpenGL.dir/src/Particles.cpp.o -c /home/andreivoiculas/OpenGL/src/Particles.cpp

CMakeFiles/OpenGL.dir/src/Particles.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OpenGL.dir/src/Particles.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/andreivoiculas/OpenGL/src/Particles.cpp > CMakeFiles/OpenGL.dir/src/Particles.cpp.i

CMakeFiles/OpenGL.dir/src/Particles.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OpenGL.dir/src/Particles.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/andreivoiculas/OpenGL/src/Particles.cpp -o CMakeFiles/OpenGL.dir/src/Particles.cpp.s

# Object files for target OpenGL
OpenGL_OBJECTS = \
"CMakeFiles/OpenGL.dir/src/main.cpp.o" \
"CMakeFiles/OpenGL.dir/src/Camera.cpp.o" \
"CMakeFiles/OpenGL.dir/src/Shader.cpp.o" \
"CMakeFiles/OpenGL.dir/src/Program.cpp.o" \
"CMakeFiles/OpenGL.dir/src/Shape.cpp.o" \
"CMakeFiles/OpenGL.dir/src/MovingShape.cpp.o" \
"CMakeFiles/OpenGL.dir/src/Particles.cpp.o"

# External object files for target OpenGL
OpenGL_EXTERNAL_OBJECTS =

OpenGL: CMakeFiles/OpenGL.dir/src/main.cpp.o
OpenGL: CMakeFiles/OpenGL.dir/src/Camera.cpp.o
OpenGL: CMakeFiles/OpenGL.dir/src/Shader.cpp.o
OpenGL: CMakeFiles/OpenGL.dir/src/Program.cpp.o
OpenGL: CMakeFiles/OpenGL.dir/src/Shape.cpp.o
OpenGL: CMakeFiles/OpenGL.dir/src/MovingShape.cpp.o
OpenGL: CMakeFiles/OpenGL.dir/src/Particles.cpp.o
OpenGL: CMakeFiles/OpenGL.dir/build.make
OpenGL: /usr/lib/x86_64-linux-gnu/libOpenGL.so
OpenGL: /usr/lib/x86_64-linux-gnu/libglfw.so.3.2
OpenGL: CMakeFiles/OpenGL.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/andreivoiculas/OpenGL/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable OpenGL"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/OpenGL.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/OpenGL.dir/build: OpenGL

.PHONY : CMakeFiles/OpenGL.dir/build

CMakeFiles/OpenGL.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/OpenGL.dir/cmake_clean.cmake
.PHONY : CMakeFiles/OpenGL.dir/clean

CMakeFiles/OpenGL.dir/depend:
	cd /home/andreivoiculas/OpenGL && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/andreivoiculas/OpenGL /home/andreivoiculas/OpenGL /home/andreivoiculas/OpenGL /home/andreivoiculas/OpenGL /home/andreivoiculas/OpenGL/CMakeFiles/OpenGL.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/OpenGL.dir/depend

