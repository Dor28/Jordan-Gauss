# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\applications\CLion 2020.3.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\applications\CLion 2020.3.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\study\programming\Jordan-Gauss

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\study\programming\Jordan-Gauss\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/jordan_gauss.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/jordan_gauss.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/jordan_gauss.dir/flags.make

CMakeFiles/jordan_gauss.dir/lss_77_05.c.obj: CMakeFiles/jordan_gauss.dir/flags.make
CMakeFiles/jordan_gauss.dir/lss_77_05.c.obj: ../lss_77_05.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\study\programming\Jordan-Gauss\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/jordan_gauss.dir/lss_77_05.c.obj"
	D:\applications\mngw\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\jordan_gauss.dir\lss_77_05.c.obj   -c D:\study\programming\Jordan-Gauss\lss_77_05.c

CMakeFiles/jordan_gauss.dir/lss_77_05.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/jordan_gauss.dir/lss_77_05.c.i"
	D:\applications\mngw\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\study\programming\Jordan-Gauss\lss_77_05.c > CMakeFiles\jordan_gauss.dir\lss_77_05.c.i

CMakeFiles/jordan_gauss.dir/lss_77_05.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/jordan_gauss.dir/lss_77_05.c.s"
	D:\applications\mngw\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\study\programming\Jordan-Gauss\lss_77_05.c -o CMakeFiles\jordan_gauss.dir\lss_77_05.c.s

CMakeFiles/jordan_gauss.dir/main_lss_77_05.c.obj: CMakeFiles/jordan_gauss.dir/flags.make
CMakeFiles/jordan_gauss.dir/main_lss_77_05.c.obj: ../main_lss_77_05.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\study\programming\Jordan-Gauss\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/jordan_gauss.dir/main_lss_77_05.c.obj"
	D:\applications\mngw\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\jordan_gauss.dir\main_lss_77_05.c.obj   -c D:\study\programming\Jordan-Gauss\main_lss_77_05.c

CMakeFiles/jordan_gauss.dir/main_lss_77_05.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/jordan_gauss.dir/main_lss_77_05.c.i"
	D:\applications\mngw\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\study\programming\Jordan-Gauss\main_lss_77_05.c > CMakeFiles\jordan_gauss.dir\main_lss_77_05.c.i

CMakeFiles/jordan_gauss.dir/main_lss_77_05.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/jordan_gauss.dir/main_lss_77_05.c.s"
	D:\applications\mngw\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\study\programming\Jordan-Gauss\main_lss_77_05.c -o CMakeFiles\jordan_gauss.dir\main_lss_77_05.c.s

# Object files for target jordan_gauss
jordan_gauss_OBJECTS = \
"CMakeFiles/jordan_gauss.dir/lss_77_05.c.obj" \
"CMakeFiles/jordan_gauss.dir/main_lss_77_05.c.obj"

# External object files for target jordan_gauss
jordan_gauss_EXTERNAL_OBJECTS =

jordan_gauss.exe: CMakeFiles/jordan_gauss.dir/lss_77_05.c.obj
jordan_gauss.exe: CMakeFiles/jordan_gauss.dir/main_lss_77_05.c.obj
jordan_gauss.exe: CMakeFiles/jordan_gauss.dir/build.make
jordan_gauss.exe: CMakeFiles/jordan_gauss.dir/linklibs.rsp
jordan_gauss.exe: CMakeFiles/jordan_gauss.dir/objects1.rsp
jordan_gauss.exe: CMakeFiles/jordan_gauss.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\study\programming\Jordan-Gauss\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable jordan_gauss.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\jordan_gauss.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/jordan_gauss.dir/build: jordan_gauss.exe

.PHONY : CMakeFiles/jordan_gauss.dir/build

CMakeFiles/jordan_gauss.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\jordan_gauss.dir\cmake_clean.cmake
.PHONY : CMakeFiles/jordan_gauss.dir/clean

CMakeFiles/jordan_gauss.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\study\programming\Jordan-Gauss D:\study\programming\Jordan-Gauss D:\study\programming\Jordan-Gauss\cmake-build-debug D:\study\programming\Jordan-Gauss\cmake-build-debug D:\study\programming\Jordan-Gauss\cmake-build-debug\CMakeFiles\jordan_gauss.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/jordan_gauss.dir/depend

