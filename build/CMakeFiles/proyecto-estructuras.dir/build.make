# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/sortextg/CodeProjects/Cpp/Project---Minewhispeer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sortextg/CodeProjects/Cpp/Project---Minewhispeer/build

# Include any dependencies generated for this target.
include CMakeFiles/proyecto-estructuras.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/proyecto-estructuras.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/proyecto-estructuras.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/proyecto-estructuras.dir/flags.make

CMakeFiles/proyecto-estructuras.dir/src/presentation/main.cpp.o: CMakeFiles/proyecto-estructuras.dir/flags.make
CMakeFiles/proyecto-estructuras.dir/src/presentation/main.cpp.o: /home/sortextg/CodeProjects/Cpp/Project---Minewhispeer/src/presentation/main.cpp
CMakeFiles/proyecto-estructuras.dir/src/presentation/main.cpp.o: CMakeFiles/proyecto-estructuras.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/sortextg/CodeProjects/Cpp/Project---Minewhispeer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/proyecto-estructuras.dir/src/presentation/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/proyecto-estructuras.dir/src/presentation/main.cpp.o -MF CMakeFiles/proyecto-estructuras.dir/src/presentation/main.cpp.o.d -o CMakeFiles/proyecto-estructuras.dir/src/presentation/main.cpp.o -c /home/sortextg/CodeProjects/Cpp/Project---Minewhispeer/src/presentation/main.cpp

CMakeFiles/proyecto-estructuras.dir/src/presentation/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/proyecto-estructuras.dir/src/presentation/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sortextg/CodeProjects/Cpp/Project---Minewhispeer/src/presentation/main.cpp > CMakeFiles/proyecto-estructuras.dir/src/presentation/main.cpp.i

CMakeFiles/proyecto-estructuras.dir/src/presentation/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/proyecto-estructuras.dir/src/presentation/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sortextg/CodeProjects/Cpp/Project---Minewhispeer/src/presentation/main.cpp -o CMakeFiles/proyecto-estructuras.dir/src/presentation/main.cpp.s

# Object files for target proyecto-estructuras
proyecto__estructuras_OBJECTS = \
"CMakeFiles/proyecto-estructuras.dir/src/presentation/main.cpp.o"

# External object files for target proyecto-estructuras
proyecto__estructuras_EXTERNAL_OBJECTS =

proyecto-estructuras: CMakeFiles/proyecto-estructuras.dir/src/presentation/main.cpp.o
proyecto-estructuras: CMakeFiles/proyecto-estructuras.dir/build.make
proyecto-estructuras: CMakeFiles/proyecto-estructuras.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/sortextg/CodeProjects/Cpp/Project---Minewhispeer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable proyecto-estructuras"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/proyecto-estructuras.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/proyecto-estructuras.dir/build: proyecto-estructuras
.PHONY : CMakeFiles/proyecto-estructuras.dir/build

CMakeFiles/proyecto-estructuras.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/proyecto-estructuras.dir/cmake_clean.cmake
.PHONY : CMakeFiles/proyecto-estructuras.dir/clean

CMakeFiles/proyecto-estructuras.dir/depend:
	cd /home/sortextg/CodeProjects/Cpp/Project---Minewhispeer/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sortextg/CodeProjects/Cpp/Project---Minewhispeer /home/sortextg/CodeProjects/Cpp/Project---Minewhispeer /home/sortextg/CodeProjects/Cpp/Project---Minewhispeer/build /home/sortextg/CodeProjects/Cpp/Project---Minewhispeer/build /home/sortextg/CodeProjects/Cpp/Project---Minewhispeer/build/CMakeFiles/proyecto-estructuras.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/proyecto-estructuras.dir/depend

