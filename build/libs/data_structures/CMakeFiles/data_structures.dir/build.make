# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.28

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\Danila\Documents\Лабы\Основы программирования\course"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Danila\Documents\Лабы\Основы программирования\course\build"

# Include any dependencies generated for this target.
include libs/data_structures/CMakeFiles/data_structures.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include libs/data_structures/CMakeFiles/data_structures.dir/compiler_depend.make

# Include the progress variables for this target.
include libs/data_structures/CMakeFiles/data_structures.dir/progress.make

# Include the compile flags for this target's objects.
include libs/data_structures/CMakeFiles/data_structures.dir/flags.make

libs/data_structures/CMakeFiles/data_structures.dir/bitset/bitset.c.obj: libs/data_structures/CMakeFiles/data_structures.dir/flags.make
libs/data_structures/CMakeFiles/data_structures.dir/bitset/bitset.c.obj: C:/Users/Danila/Documents/Лабы/Основы\ программирования/course/libs/data_structures/bitset/bitset.c
libs/data_structures/CMakeFiles/data_structures.dir/bitset/bitset.c.obj: libs/data_structures/CMakeFiles/data_structures.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="C:\Users\Danila\Documents\Лабы\Основы программирования\course\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object libs/data_structures/CMakeFiles/data_structures.dir/bitset/bitset.c.obj"
	cd /d C:\Users\Danila\DOCUME~1\4313~1\EB3F~1\course\build\libs\DATA_S~1 && C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT libs/data_structures/CMakeFiles/data_structures.dir/bitset/bitset.c.obj -MF CMakeFiles\data_structures.dir\bitset\bitset.c.obj.d -o CMakeFiles\data_structures.dir\bitset\bitset.c.obj -c "C:\Users\Danila\Documents\Лабы\Основы программирования\course\libs\data_structures\bitset\bitset.c"

libs/data_structures/CMakeFiles/data_structures.dir/bitset/bitset.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/data_structures.dir/bitset/bitset.c.i"
	cd /d C:\Users\Danila\DOCUME~1\4313~1\EB3F~1\course\build\libs\DATA_S~1 && C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\Danila\Documents\Лабы\Основы программирования\course\libs\data_structures\bitset\bitset.c" > CMakeFiles\data_structures.dir\bitset\bitset.c.i

libs/data_structures/CMakeFiles/data_structures.dir/bitset/bitset.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/data_structures.dir/bitset/bitset.c.s"
	cd /d C:\Users\Danila\DOCUME~1\4313~1\EB3F~1\course\build\libs\DATA_S~1 && C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\Danila\Documents\Лабы\Основы программирования\course\libs\data_structures\bitset\bitset.c" -o CMakeFiles\data_structures.dir\bitset\bitset.c.s

libs/data_structures/CMakeFiles/data_structures.dir/unordered_set/unordered_array_set.c.obj: libs/data_structures/CMakeFiles/data_structures.dir/flags.make
libs/data_structures/CMakeFiles/data_structures.dir/unordered_set/unordered_array_set.c.obj: C:/Users/Danila/Documents/Лабы/Основы\ программирования/course/libs/data_structures/unordered_set/unordered_array_set.c
libs/data_structures/CMakeFiles/data_structures.dir/unordered_set/unordered_array_set.c.obj: libs/data_structures/CMakeFiles/data_structures.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="C:\Users\Danila\Documents\Лабы\Основы программирования\course\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object libs/data_structures/CMakeFiles/data_structures.dir/unordered_set/unordered_array_set.c.obj"
	cd /d C:\Users\Danila\DOCUME~1\4313~1\EB3F~1\course\build\libs\DATA_S~1 && C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT libs/data_structures/CMakeFiles/data_structures.dir/unordered_set/unordered_array_set.c.obj -MF CMakeFiles\data_structures.dir\unordered_set\unordered_array_set.c.obj.d -o CMakeFiles\data_structures.dir\unordered_set\unordered_array_set.c.obj -c "C:\Users\Danila\Documents\Лабы\Основы программирования\course\libs\data_structures\unordered_set\unordered_array_set.c"

libs/data_structures/CMakeFiles/data_structures.dir/unordered_set/unordered_array_set.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/data_structures.dir/unordered_set/unordered_array_set.c.i"
	cd /d C:\Users\Danila\DOCUME~1\4313~1\EB3F~1\course\build\libs\DATA_S~1 && C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\Danila\Documents\Лабы\Основы программирования\course\libs\data_structures\unordered_set\unordered_array_set.c" > CMakeFiles\data_structures.dir\unordered_set\unordered_array_set.c.i

libs/data_structures/CMakeFiles/data_structures.dir/unordered_set/unordered_array_set.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/data_structures.dir/unordered_set/unordered_array_set.c.s"
	cd /d C:\Users\Danila\DOCUME~1\4313~1\EB3F~1\course\build\libs\DATA_S~1 && C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\Danila\Documents\Лабы\Основы программирования\course\libs\data_structures\unordered_set\unordered_array_set.c" -o CMakeFiles\data_structures.dir\unordered_set\unordered_array_set.c.s

libs/data_structures/CMakeFiles/data_structures.dir/ordered_set/ordered_array_set.c.obj: libs/data_structures/CMakeFiles/data_structures.dir/flags.make
libs/data_structures/CMakeFiles/data_structures.dir/ordered_set/ordered_array_set.c.obj: C:/Users/Danila/Documents/Лабы/Основы\ программирования/course/libs/data_structures/ordered_set/ordered_array_set.c
libs/data_structures/CMakeFiles/data_structures.dir/ordered_set/ordered_array_set.c.obj: libs/data_structures/CMakeFiles/data_structures.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="C:\Users\Danila\Documents\Лабы\Основы программирования\course\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building C object libs/data_structures/CMakeFiles/data_structures.dir/ordered_set/ordered_array_set.c.obj"
	cd /d C:\Users\Danila\DOCUME~1\4313~1\EB3F~1\course\build\libs\DATA_S~1 && C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT libs/data_structures/CMakeFiles/data_structures.dir/ordered_set/ordered_array_set.c.obj -MF CMakeFiles\data_structures.dir\ordered_set\ordered_array_set.c.obj.d -o CMakeFiles\data_structures.dir\ordered_set\ordered_array_set.c.obj -c "C:\Users\Danila\Documents\Лабы\Основы программирования\course\libs\data_structures\ordered_set\ordered_array_set.c"

libs/data_structures/CMakeFiles/data_structures.dir/ordered_set/ordered_array_set.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/data_structures.dir/ordered_set/ordered_array_set.c.i"
	cd /d C:\Users\Danila\DOCUME~1\4313~1\EB3F~1\course\build\libs\DATA_S~1 && C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\Danila\Documents\Лабы\Основы программирования\course\libs\data_structures\ordered_set\ordered_array_set.c" > CMakeFiles\data_structures.dir\ordered_set\ordered_array_set.c.i

libs/data_structures/CMakeFiles/data_structures.dir/ordered_set/ordered_array_set.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/data_structures.dir/ordered_set/ordered_array_set.c.s"
	cd /d C:\Users\Danila\DOCUME~1\4313~1\EB3F~1\course\build\libs\DATA_S~1 && C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\Danila\Documents\Лабы\Основы программирования\course\libs\data_structures\ordered_set\ordered_array_set.c" -o CMakeFiles\data_structures.dir\ordered_set\ordered_array_set.c.s

libs/data_structures/CMakeFiles/data_structures.dir/vector/vector.c.obj: libs/data_structures/CMakeFiles/data_structures.dir/flags.make
libs/data_structures/CMakeFiles/data_structures.dir/vector/vector.c.obj: C:/Users/Danila/Documents/Лабы/Основы\ программирования/course/libs/data_structures/vector/vector.c
libs/data_structures/CMakeFiles/data_structures.dir/vector/vector.c.obj: libs/data_structures/CMakeFiles/data_structures.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="C:\Users\Danila\Documents\Лабы\Основы программирования\course\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building C object libs/data_structures/CMakeFiles/data_structures.dir/vector/vector.c.obj"
	cd /d C:\Users\Danila\DOCUME~1\4313~1\EB3F~1\course\build\libs\DATA_S~1 && C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT libs/data_structures/CMakeFiles/data_structures.dir/vector/vector.c.obj -MF CMakeFiles\data_structures.dir\vector\vector.c.obj.d -o CMakeFiles\data_structures.dir\vector\vector.c.obj -c "C:\Users\Danila\Documents\Лабы\Основы программирования\course\libs\data_structures\vector\vector.c"

libs/data_structures/CMakeFiles/data_structures.dir/vector/vector.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/data_structures.dir/vector/vector.c.i"
	cd /d C:\Users\Danila\DOCUME~1\4313~1\EB3F~1\course\build\libs\DATA_S~1 && C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\Danila\Documents\Лабы\Основы программирования\course\libs\data_structures\vector\vector.c" > CMakeFiles\data_structures.dir\vector\vector.c.i

libs/data_structures/CMakeFiles/data_structures.dir/vector/vector.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/data_structures.dir/vector/vector.c.s"
	cd /d C:\Users\Danila\DOCUME~1\4313~1\EB3F~1\course\build\libs\DATA_S~1 && C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\Danila\Documents\Лабы\Основы программирования\course\libs\data_structures\vector\vector.c" -o CMakeFiles\data_structures.dir\vector\vector.c.s

libs/data_structures/CMakeFiles/data_structures.dir/vector/vectorVoid.c.obj: libs/data_structures/CMakeFiles/data_structures.dir/flags.make
libs/data_structures/CMakeFiles/data_structures.dir/vector/vectorVoid.c.obj: C:/Users/Danila/Documents/Лабы/Основы\ программирования/course/libs/data_structures/vector/vectorVoid.c
libs/data_structures/CMakeFiles/data_structures.dir/vector/vectorVoid.c.obj: libs/data_structures/CMakeFiles/data_structures.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="C:\Users\Danila\Documents\Лабы\Основы программирования\course\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building C object libs/data_structures/CMakeFiles/data_structures.dir/vector/vectorVoid.c.obj"
	cd /d C:\Users\Danila\DOCUME~1\4313~1\EB3F~1\course\build\libs\DATA_S~1 && C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT libs/data_structures/CMakeFiles/data_structures.dir/vector/vectorVoid.c.obj -MF CMakeFiles\data_structures.dir\vector\vectorVoid.c.obj.d -o CMakeFiles\data_structures.dir\vector\vectorVoid.c.obj -c "C:\Users\Danila\Documents\Лабы\Основы программирования\course\libs\data_structures\vector\vectorVoid.c"

libs/data_structures/CMakeFiles/data_structures.dir/vector/vectorVoid.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/data_structures.dir/vector/vectorVoid.c.i"
	cd /d C:\Users\Danila\DOCUME~1\4313~1\EB3F~1\course\build\libs\DATA_S~1 && C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\Danila\Documents\Лабы\Основы программирования\course\libs\data_structures\vector\vectorVoid.c" > CMakeFiles\data_structures.dir\vector\vectorVoid.c.i

libs/data_structures/CMakeFiles/data_structures.dir/vector/vectorVoid.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/data_structures.dir/vector/vectorVoid.c.s"
	cd /d C:\Users\Danila\DOCUME~1\4313~1\EB3F~1\course\build\libs\DATA_S~1 && C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\Danila\Documents\Лабы\Основы программирования\course\libs\data_structures\vector\vectorVoid.c" -o CMakeFiles\data_structures.dir\vector\vectorVoid.c.s

# Object files for target data_structures
data_structures_OBJECTS = \
"CMakeFiles/data_structures.dir/bitset/bitset.c.obj" \
"CMakeFiles/data_structures.dir/unordered_set/unordered_array_set.c.obj" \
"CMakeFiles/data_structures.dir/ordered_set/ordered_array_set.c.obj" \
"CMakeFiles/data_structures.dir/vector/vector.c.obj" \
"CMakeFiles/data_structures.dir/vector/vectorVoid.c.obj"

# External object files for target data_structures
data_structures_EXTERNAL_OBJECTS =

libs/data_structures/libdata_structures.a: libs/data_structures/CMakeFiles/data_structures.dir/bitset/bitset.c.obj
libs/data_structures/libdata_structures.a: libs/data_structures/CMakeFiles/data_structures.dir/unordered_set/unordered_array_set.c.obj
libs/data_structures/libdata_structures.a: libs/data_structures/CMakeFiles/data_structures.dir/ordered_set/ordered_array_set.c.obj
libs/data_structures/libdata_structures.a: libs/data_structures/CMakeFiles/data_structures.dir/vector/vector.c.obj
libs/data_structures/libdata_structures.a: libs/data_structures/CMakeFiles/data_structures.dir/vector/vectorVoid.c.obj
libs/data_structures/libdata_structures.a: libs/data_structures/CMakeFiles/data_structures.dir/build.make
libs/data_structures/libdata_structures.a: libs/data_structures/CMakeFiles/data_structures.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="C:\Users\Danila\Documents\Лабы\Основы программирования\course\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Linking C static library libdata_structures.a"
	cd /d C:\Users\Danila\DOCUME~1\4313~1\EB3F~1\course\build\libs\DATA_S~1 && $(CMAKE_COMMAND) -P CMakeFiles\data_structures.dir\cmake_clean_target.cmake
	cd /d C:\Users\Danila\DOCUME~1\4313~1\EB3F~1\course\build\libs\DATA_S~1 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\data_structures.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
libs/data_structures/CMakeFiles/data_structures.dir/build: libs/data_structures/libdata_structures.a
.PHONY : libs/data_structures/CMakeFiles/data_structures.dir/build

libs/data_structures/CMakeFiles/data_structures.dir/clean:
	cd /d C:\Users\Danila\DOCUME~1\4313~1\EB3F~1\course\build\libs\DATA_S~1 && $(CMAKE_COMMAND) -P CMakeFiles\data_structures.dir\cmake_clean.cmake
.PHONY : libs/data_structures/CMakeFiles/data_structures.dir/clean

libs/data_structures/CMakeFiles/data_structures.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Danila\Documents\Лабы\Основы программирования\course" "C:\Users\Danila\Documents\Лабы\Основы программирования\course\libs\data_structures" "C:\Users\Danila\Documents\Лабы\Основы программирования\course\build" "C:\Users\Danila\Documents\Лабы\Основы программирования\course\build\libs\data_structures" "C:\Users\Danila\Documents\Лабы\Основы программирования\course\build\libs\data_structures\CMakeFiles\data_structures.dir\DependInfo.cmake" "--color=$(COLOR)"
.PHONY : libs/data_structures/CMakeFiles/data_structures.dir/depend
