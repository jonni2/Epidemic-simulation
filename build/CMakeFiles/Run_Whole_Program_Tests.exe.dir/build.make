# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /mnt/c/Users/User/Desktop/Epidemic-simulation

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/User/Desktop/Epidemic-simulation/build

# Include any dependencies generated for this target.
include CMakeFiles/Run_Whole_Program_Tests.exe.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Run_Whole_Program_Tests.exe.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Run_Whole_Program_Tests.exe.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Run_Whole_Program_Tests.exe.dir/flags.make

CMakeFiles/Run_Whole_Program_Tests.exe.dir/Tests/run_tests.cpp.o: CMakeFiles/Run_Whole_Program_Tests.exe.dir/flags.make
CMakeFiles/Run_Whole_Program_Tests.exe.dir/Tests/run_tests.cpp.o: ../Tests/run_tests.cpp
CMakeFiles/Run_Whole_Program_Tests.exe.dir/Tests/run_tests.cpp.o: CMakeFiles/Run_Whole_Program_Tests.exe.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/User/Desktop/Epidemic-simulation/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Run_Whole_Program_Tests.exe.dir/Tests/run_tests.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Run_Whole_Program_Tests.exe.dir/Tests/run_tests.cpp.o -MF CMakeFiles/Run_Whole_Program_Tests.exe.dir/Tests/run_tests.cpp.o.d -o CMakeFiles/Run_Whole_Program_Tests.exe.dir/Tests/run_tests.cpp.o -c /mnt/c/Users/User/Desktop/Epidemic-simulation/Tests/run_tests.cpp

CMakeFiles/Run_Whole_Program_Tests.exe.dir/Tests/run_tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Run_Whole_Program_Tests.exe.dir/Tests/run_tests.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/User/Desktop/Epidemic-simulation/Tests/run_tests.cpp > CMakeFiles/Run_Whole_Program_Tests.exe.dir/Tests/run_tests.cpp.i

CMakeFiles/Run_Whole_Program_Tests.exe.dir/Tests/run_tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Run_Whole_Program_Tests.exe.dir/Tests/run_tests.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/User/Desktop/Epidemic-simulation/Tests/run_tests.cpp -o CMakeFiles/Run_Whole_Program_Tests.exe.dir/Tests/run_tests.cpp.s

CMakeFiles/Run_Whole_Program_Tests.exe.dir/Tests/Whole_Program_Tests/whole_program_test.cpp.o: CMakeFiles/Run_Whole_Program_Tests.exe.dir/flags.make
CMakeFiles/Run_Whole_Program_Tests.exe.dir/Tests/Whole_Program_Tests/whole_program_test.cpp.o: ../Tests/Whole_Program_Tests/whole_program_test.cpp
CMakeFiles/Run_Whole_Program_Tests.exe.dir/Tests/Whole_Program_Tests/whole_program_test.cpp.o: CMakeFiles/Run_Whole_Program_Tests.exe.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/User/Desktop/Epidemic-simulation/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Run_Whole_Program_Tests.exe.dir/Tests/Whole_Program_Tests/whole_program_test.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Run_Whole_Program_Tests.exe.dir/Tests/Whole_Program_Tests/whole_program_test.cpp.o -MF CMakeFiles/Run_Whole_Program_Tests.exe.dir/Tests/Whole_Program_Tests/whole_program_test.cpp.o.d -o CMakeFiles/Run_Whole_Program_Tests.exe.dir/Tests/Whole_Program_Tests/whole_program_test.cpp.o -c /mnt/c/Users/User/Desktop/Epidemic-simulation/Tests/Whole_Program_Tests/whole_program_test.cpp

CMakeFiles/Run_Whole_Program_Tests.exe.dir/Tests/Whole_Program_Tests/whole_program_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Run_Whole_Program_Tests.exe.dir/Tests/Whole_Program_Tests/whole_program_test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/User/Desktop/Epidemic-simulation/Tests/Whole_Program_Tests/whole_program_test.cpp > CMakeFiles/Run_Whole_Program_Tests.exe.dir/Tests/Whole_Program_Tests/whole_program_test.cpp.i

CMakeFiles/Run_Whole_Program_Tests.exe.dir/Tests/Whole_Program_Tests/whole_program_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Run_Whole_Program_Tests.exe.dir/Tests/Whole_Program_Tests/whole_program_test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/User/Desktop/Epidemic-simulation/Tests/Whole_Program_Tests/whole_program_test.cpp -o CMakeFiles/Run_Whole_Program_Tests.exe.dir/Tests/Whole_Program_Tests/whole_program_test.cpp.s

CMakeFiles/Run_Whole_Program_Tests.exe.dir/Board_Utilities/board.cpp.o: CMakeFiles/Run_Whole_Program_Tests.exe.dir/flags.make
CMakeFiles/Run_Whole_Program_Tests.exe.dir/Board_Utilities/board.cpp.o: ../Board_Utilities/board.cpp
CMakeFiles/Run_Whole_Program_Tests.exe.dir/Board_Utilities/board.cpp.o: CMakeFiles/Run_Whole_Program_Tests.exe.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/User/Desktop/Epidemic-simulation/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Run_Whole_Program_Tests.exe.dir/Board_Utilities/board.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Run_Whole_Program_Tests.exe.dir/Board_Utilities/board.cpp.o -MF CMakeFiles/Run_Whole_Program_Tests.exe.dir/Board_Utilities/board.cpp.o.d -o CMakeFiles/Run_Whole_Program_Tests.exe.dir/Board_Utilities/board.cpp.o -c /mnt/c/Users/User/Desktop/Epidemic-simulation/Board_Utilities/board.cpp

CMakeFiles/Run_Whole_Program_Tests.exe.dir/Board_Utilities/board.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Run_Whole_Program_Tests.exe.dir/Board_Utilities/board.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/User/Desktop/Epidemic-simulation/Board_Utilities/board.cpp > CMakeFiles/Run_Whole_Program_Tests.exe.dir/Board_Utilities/board.cpp.i

CMakeFiles/Run_Whole_Program_Tests.exe.dir/Board_Utilities/board.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Run_Whole_Program_Tests.exe.dir/Board_Utilities/board.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/User/Desktop/Epidemic-simulation/Board_Utilities/board.cpp -o CMakeFiles/Run_Whole_Program_Tests.exe.dir/Board_Utilities/board.cpp.s

CMakeFiles/Run_Whole_Program_Tests.exe.dir/Board_Evolution/evolve.cpp.o: CMakeFiles/Run_Whole_Program_Tests.exe.dir/flags.make
CMakeFiles/Run_Whole_Program_Tests.exe.dir/Board_Evolution/evolve.cpp.o: ../Board_Evolution/evolve.cpp
CMakeFiles/Run_Whole_Program_Tests.exe.dir/Board_Evolution/evolve.cpp.o: CMakeFiles/Run_Whole_Program_Tests.exe.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/User/Desktop/Epidemic-simulation/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Run_Whole_Program_Tests.exe.dir/Board_Evolution/evolve.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Run_Whole_Program_Tests.exe.dir/Board_Evolution/evolve.cpp.o -MF CMakeFiles/Run_Whole_Program_Tests.exe.dir/Board_Evolution/evolve.cpp.o.d -o CMakeFiles/Run_Whole_Program_Tests.exe.dir/Board_Evolution/evolve.cpp.o -c /mnt/c/Users/User/Desktop/Epidemic-simulation/Board_Evolution/evolve.cpp

CMakeFiles/Run_Whole_Program_Tests.exe.dir/Board_Evolution/evolve.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Run_Whole_Program_Tests.exe.dir/Board_Evolution/evolve.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/User/Desktop/Epidemic-simulation/Board_Evolution/evolve.cpp > CMakeFiles/Run_Whole_Program_Tests.exe.dir/Board_Evolution/evolve.cpp.i

CMakeFiles/Run_Whole_Program_Tests.exe.dir/Board_Evolution/evolve.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Run_Whole_Program_Tests.exe.dir/Board_Evolution/evolve.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/User/Desktop/Epidemic-simulation/Board_Evolution/evolve.cpp -o CMakeFiles/Run_Whole_Program_Tests.exe.dir/Board_Evolution/evolve.cpp.s

CMakeFiles/Run_Whole_Program_Tests.exe.dir/Board_Evolution/step.cpp.o: CMakeFiles/Run_Whole_Program_Tests.exe.dir/flags.make
CMakeFiles/Run_Whole_Program_Tests.exe.dir/Board_Evolution/step.cpp.o: ../Board_Evolution/step.cpp
CMakeFiles/Run_Whole_Program_Tests.exe.dir/Board_Evolution/step.cpp.o: CMakeFiles/Run_Whole_Program_Tests.exe.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/User/Desktop/Epidemic-simulation/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Run_Whole_Program_Tests.exe.dir/Board_Evolution/step.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Run_Whole_Program_Tests.exe.dir/Board_Evolution/step.cpp.o -MF CMakeFiles/Run_Whole_Program_Tests.exe.dir/Board_Evolution/step.cpp.o.d -o CMakeFiles/Run_Whole_Program_Tests.exe.dir/Board_Evolution/step.cpp.o -c /mnt/c/Users/User/Desktop/Epidemic-simulation/Board_Evolution/step.cpp

CMakeFiles/Run_Whole_Program_Tests.exe.dir/Board_Evolution/step.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Run_Whole_Program_Tests.exe.dir/Board_Evolution/step.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/User/Desktop/Epidemic-simulation/Board_Evolution/step.cpp > CMakeFiles/Run_Whole_Program_Tests.exe.dir/Board_Evolution/step.cpp.i

CMakeFiles/Run_Whole_Program_Tests.exe.dir/Board_Evolution/step.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Run_Whole_Program_Tests.exe.dir/Board_Evolution/step.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/User/Desktop/Epidemic-simulation/Board_Evolution/step.cpp -o CMakeFiles/Run_Whole_Program_Tests.exe.dir/Board_Evolution/step.cpp.s

# Object files for target Run_Whole_Program_Tests.exe
Run_Whole_Program_Tests_exe_OBJECTS = \
"CMakeFiles/Run_Whole_Program_Tests.exe.dir/Tests/run_tests.cpp.o" \
"CMakeFiles/Run_Whole_Program_Tests.exe.dir/Tests/Whole_Program_Tests/whole_program_test.cpp.o" \
"CMakeFiles/Run_Whole_Program_Tests.exe.dir/Board_Utilities/board.cpp.o" \
"CMakeFiles/Run_Whole_Program_Tests.exe.dir/Board_Evolution/evolve.cpp.o" \
"CMakeFiles/Run_Whole_Program_Tests.exe.dir/Board_Evolution/step.cpp.o"

# External object files for target Run_Whole_Program_Tests.exe
Run_Whole_Program_Tests_exe_EXTERNAL_OBJECTS =

Run_Whole_Program_Tests.exe: CMakeFiles/Run_Whole_Program_Tests.exe.dir/Tests/run_tests.cpp.o
Run_Whole_Program_Tests.exe: CMakeFiles/Run_Whole_Program_Tests.exe.dir/Tests/Whole_Program_Tests/whole_program_test.cpp.o
Run_Whole_Program_Tests.exe: CMakeFiles/Run_Whole_Program_Tests.exe.dir/Board_Utilities/board.cpp.o
Run_Whole_Program_Tests.exe: CMakeFiles/Run_Whole_Program_Tests.exe.dir/Board_Evolution/evolve.cpp.o
Run_Whole_Program_Tests.exe: CMakeFiles/Run_Whole_Program_Tests.exe.dir/Board_Evolution/step.cpp.o
Run_Whole_Program_Tests.exe: CMakeFiles/Run_Whole_Program_Tests.exe.dir/build.make
Run_Whole_Program_Tests.exe: CMakeFiles/Run_Whole_Program_Tests.exe.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/User/Desktop/Epidemic-simulation/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable Run_Whole_Program_Tests.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Run_Whole_Program_Tests.exe.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Run_Whole_Program_Tests.exe.dir/build: Run_Whole_Program_Tests.exe
.PHONY : CMakeFiles/Run_Whole_Program_Tests.exe.dir/build

CMakeFiles/Run_Whole_Program_Tests.exe.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Run_Whole_Program_Tests.exe.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Run_Whole_Program_Tests.exe.dir/clean

CMakeFiles/Run_Whole_Program_Tests.exe.dir/depend:
	cd /mnt/c/Users/User/Desktop/Epidemic-simulation/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/User/Desktop/Epidemic-simulation /mnt/c/Users/User/Desktop/Epidemic-simulation /mnt/c/Users/User/Desktop/Epidemic-simulation/build /mnt/c/Users/User/Desktop/Epidemic-simulation/build /mnt/c/Users/User/Desktop/Epidemic-simulation/build/CMakeFiles/Run_Whole_Program_Tests.exe.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Run_Whole_Program_Tests.exe.dir/depend

