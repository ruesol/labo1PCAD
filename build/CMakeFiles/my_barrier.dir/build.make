# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.31

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
CMAKE_COMMAND = /opt/homebrew/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/russellbonelli/Library/Mobile Documents/com~apple~CloudDocs/UNI/PCAD/labo1CC"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/russellbonelli/Library/Mobile Documents/com~apple~CloudDocs/UNI/PCAD/labo1CC/build"

# Include any dependencies generated for this target.
include CMakeFiles/my_barrier.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/my_barrier.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/my_barrier.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/my_barrier.dir/flags.make

CMakeFiles/my_barrier.dir/codegen:
.PHONY : CMakeFiles/my_barrier.dir/codegen

CMakeFiles/my_barrier.dir/barrier.c.o: CMakeFiles/my_barrier.dir/flags.make
CMakeFiles/my_barrier.dir/barrier.c.o: /Users/russellbonelli/Library/Mobile\ Documents/com~apple~CloudDocs/UNI/PCAD/labo1CC/barrier.c
CMakeFiles/my_barrier.dir/barrier.c.o: CMakeFiles/my_barrier.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/russellbonelli/Library/Mobile Documents/com~apple~CloudDocs/UNI/PCAD/labo1CC/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/my_barrier.dir/barrier.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/my_barrier.dir/barrier.c.o -MF CMakeFiles/my_barrier.dir/barrier.c.o.d -o CMakeFiles/my_barrier.dir/barrier.c.o -c "/Users/russellbonelli/Library/Mobile Documents/com~apple~CloudDocs/UNI/PCAD/labo1CC/barrier.c"

CMakeFiles/my_barrier.dir/barrier.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/my_barrier.dir/barrier.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/russellbonelli/Library/Mobile Documents/com~apple~CloudDocs/UNI/PCAD/labo1CC/barrier.c" > CMakeFiles/my_barrier.dir/barrier.c.i

CMakeFiles/my_barrier.dir/barrier.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/my_barrier.dir/barrier.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/russellbonelli/Library/Mobile Documents/com~apple~CloudDocs/UNI/PCAD/labo1CC/barrier.c" -o CMakeFiles/my_barrier.dir/barrier.c.s

# Object files for target my_barrier
my_barrier_OBJECTS = \
"CMakeFiles/my_barrier.dir/barrier.c.o"

# External object files for target my_barrier
my_barrier_EXTERNAL_OBJECTS =

my_barrier: CMakeFiles/my_barrier.dir/barrier.c.o
my_barrier: CMakeFiles/my_barrier.dir/build.make
my_barrier: CMakeFiles/my_barrier.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="/Users/russellbonelli/Library/Mobile Documents/com~apple~CloudDocs/UNI/PCAD/labo1CC/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable my_barrier"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/my_barrier.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/my_barrier.dir/build: my_barrier
.PHONY : CMakeFiles/my_barrier.dir/build

CMakeFiles/my_barrier.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/my_barrier.dir/cmake_clean.cmake
.PHONY : CMakeFiles/my_barrier.dir/clean

CMakeFiles/my_barrier.dir/depend:
	cd "/Users/russellbonelli/Library/Mobile Documents/com~apple~CloudDocs/UNI/PCAD/labo1CC/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/russellbonelli/Library/Mobile Documents/com~apple~CloudDocs/UNI/PCAD/labo1CC" "/Users/russellbonelli/Library/Mobile Documents/com~apple~CloudDocs/UNI/PCAD/labo1CC" "/Users/russellbonelli/Library/Mobile Documents/com~apple~CloudDocs/UNI/PCAD/labo1CC/build" "/Users/russellbonelli/Library/Mobile Documents/com~apple~CloudDocs/UNI/PCAD/labo1CC/build" "/Users/russellbonelli/Library/Mobile Documents/com~apple~CloudDocs/UNI/PCAD/labo1CC/build/CMakeFiles/my_barrier.dir/DependInfo.cmake" "--color=$(COLOR)"
.PHONY : CMakeFiles/my_barrier.dir/depend

