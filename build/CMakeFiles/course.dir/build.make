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
include CMakeFiles/course.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/course.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/course.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/course.dir/flags.make

CMakeFiles/course.dir/main.c.obj: CMakeFiles/course.dir/flags.make
CMakeFiles/course.dir/main.c.obj: C:/Users/Danila/Documents/Лабы/Основы\ программирования/course/main.c
CMakeFiles/course.dir/main.c.obj: CMakeFiles/course.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="C:\Users\Danila\Documents\Лабы\Основы программирования\course\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/course.dir/main.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/course.dir/main.c.obj -MF CMakeFiles\course.dir\main.c.obj.d -o CMakeFiles\course.dir\main.c.obj -c "C:\Users\Danila\Documents\Лабы\Основы программирования\course\main.c"

CMakeFiles/course.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/course.dir/main.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\Danila\Documents\Лабы\Основы программирования\course\main.c" > CMakeFiles\course.dir\main.c.i

CMakeFiles/course.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/course.dir/main.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\Danila\Documents\Лабы\Основы программирования\course\main.c" -o CMakeFiles\course.dir\main.c.s

CMakeFiles/course.dir/vec.c.obj: CMakeFiles/course.dir/flags.make
CMakeFiles/course.dir/vec.c.obj: C:/Users/Danila/Documents/Лабы/Основы\ программирования/course/vec.c
CMakeFiles/course.dir/vec.c.obj: CMakeFiles/course.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="C:\Users\Danila\Documents\Лабы\Основы программирования\course\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/course.dir/vec.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/course.dir/vec.c.obj -MF CMakeFiles\course.dir\vec.c.obj.d -o CMakeFiles\course.dir\vec.c.obj -c "C:\Users\Danila\Documents\Лабы\Основы программирования\course\vec.c"

CMakeFiles/course.dir/vec.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/course.dir/vec.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\Danila\Documents\Лабы\Основы программирования\course\vec.c" > CMakeFiles\course.dir\vec.c.i

CMakeFiles/course.dir/vec.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/course.dir/vec.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\Danila\Documents\Лабы\Основы программирования\course\vec.c" -o CMakeFiles\course.dir\vec.c.s

CMakeFiles/course.dir/vecV.c.obj: CMakeFiles/course.dir/flags.make
CMakeFiles/course.dir/vecV.c.obj: C:/Users/Danila/Documents/Лабы/Основы\ программирования/course/vecV.c
CMakeFiles/course.dir/vecV.c.obj: CMakeFiles/course.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="C:\Users\Danila\Documents\Лабы\Основы программирования\course\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/course.dir/vecV.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/course.dir/vecV.c.obj -MF CMakeFiles\course.dir\vecV.c.obj.d -o CMakeFiles\course.dir\vecV.c.obj -c "C:\Users\Danila\Documents\Лабы\Основы программирования\course\vecV.c"

CMakeFiles/course.dir/vecV.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/course.dir/vecV.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\Danila\Documents\Лабы\Основы программирования\course\vecV.c" > CMakeFiles\course.dir\vecV.c.i

CMakeFiles/course.dir/vecV.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/course.dir/vecV.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\Danila\Documents\Лабы\Основы программирования\course\vecV.c" -o CMakeFiles\course.dir\vecV.c.s

CMakeFiles/course.dir/matrix_test.c.obj: CMakeFiles/course.dir/flags.make
CMakeFiles/course.dir/matrix_test.c.obj: C:/Users/Danila/Documents/Лабы/Основы\ программирования/course/matrix_test.c
CMakeFiles/course.dir/matrix_test.c.obj: CMakeFiles/course.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="C:\Users\Danila\Documents\Лабы\Основы программирования\course\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/course.dir/matrix_test.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/course.dir/matrix_test.c.obj -MF CMakeFiles\course.dir\matrix_test.c.obj.d -o CMakeFiles\course.dir\matrix_test.c.obj -c "C:\Users\Danila\Documents\Лабы\Основы программирования\course\matrix_test.c"

CMakeFiles/course.dir/matrix_test.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/course.dir/matrix_test.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\Danila\Documents\Лабы\Основы программирования\course\matrix_test.c" > CMakeFiles\course.dir\matrix_test.c.i

CMakeFiles/course.dir/matrix_test.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/course.dir/matrix_test.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\Danila\Documents\Лабы\Основы программирования\course\matrix_test.c" -o CMakeFiles\course.dir\matrix_test.c.s

CMakeFiles/course.dir/matrix_ex.c.obj: CMakeFiles/course.dir/flags.make
CMakeFiles/course.dir/matrix_ex.c.obj: C:/Users/Danila/Documents/Лабы/Основы\ программирования/course/matrix_ex.c
CMakeFiles/course.dir/matrix_ex.c.obj: CMakeFiles/course.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="C:\Users\Danila\Documents\Лабы\Основы программирования\course\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/course.dir/matrix_ex.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/course.dir/matrix_ex.c.obj -MF CMakeFiles\course.dir\matrix_ex.c.obj.d -o CMakeFiles\course.dir\matrix_ex.c.obj -c "C:\Users\Danila\Documents\Лабы\Основы программирования\course\matrix_ex.c"

CMakeFiles/course.dir/matrix_ex.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/course.dir/matrix_ex.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\Danila\Documents\Лабы\Основы программирования\course\matrix_ex.c" > CMakeFiles\course.dir\matrix_ex.c.i

CMakeFiles/course.dir/matrix_ex.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/course.dir/matrix_ex.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\Danila\Documents\Лабы\Основы программирования\course\matrix_ex.c" -o CMakeFiles\course.dir\matrix_ex.c.s

CMakeFiles/course.dir/libs/data_structures/string/tasks/str_test.c.obj: CMakeFiles/course.dir/flags.make
CMakeFiles/course.dir/libs/data_structures/string/tasks/str_test.c.obj: C:/Users/Danila/Documents/Лабы/Основы\ программирования/course/libs/data_structures/string/tasks/str_test.c
CMakeFiles/course.dir/libs/data_structures/string/tasks/str_test.c.obj: CMakeFiles/course.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="C:\Users\Danila\Documents\Лабы\Основы программирования\course\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/course.dir/libs/data_structures/string/tasks/str_test.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/course.dir/libs/data_structures/string/tasks/str_test.c.obj -MF CMakeFiles\course.dir\libs\data_structures\string\tasks\str_test.c.obj.d -o CMakeFiles\course.dir\libs\data_structures\string\tasks\str_test.c.obj -c "C:\Users\Danila\Documents\Лабы\Основы программирования\course\libs\data_structures\string\tasks\str_test.c"

CMakeFiles/course.dir/libs/data_structures/string/tasks/str_test.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/course.dir/libs/data_structures/string/tasks/str_test.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\Danila\Documents\Лабы\Основы программирования\course\libs\data_structures\string\tasks\str_test.c" > CMakeFiles\course.dir\libs\data_structures\string\tasks\str_test.c.i

CMakeFiles/course.dir/libs/data_structures/string/tasks/str_test.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/course.dir/libs/data_structures/string/tasks/str_test.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\Danila\Documents\Лабы\Основы программирования\course\libs\data_structures\string\tasks\str_test.c" -o CMakeFiles\course.dir\libs\data_structures\string\tasks\str_test.c.s

CMakeFiles/course.dir/libs/data_structures/string/tasks/str_test_2.c.obj: CMakeFiles/course.dir/flags.make
CMakeFiles/course.dir/libs/data_structures/string/tasks/str_test_2.c.obj: C:/Users/Danila/Documents/Лабы/Основы\ программирования/course/libs/data_structures/string/tasks/str_test_2.c
CMakeFiles/course.dir/libs/data_structures/string/tasks/str_test_2.c.obj: CMakeFiles/course.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="C:\Users\Danila\Documents\Лабы\Основы программирования\course\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/course.dir/libs/data_structures/string/tasks/str_test_2.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/course.dir/libs/data_structures/string/tasks/str_test_2.c.obj -MF CMakeFiles\course.dir\libs\data_structures\string\tasks\str_test_2.c.obj.d -o CMakeFiles\course.dir\libs\data_structures\string\tasks\str_test_2.c.obj -c "C:\Users\Danila\Documents\Лабы\Основы программирования\course\libs\data_structures\string\tasks\str_test_2.c"

CMakeFiles/course.dir/libs/data_structures/string/tasks/str_test_2.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/course.dir/libs/data_structures/string/tasks/str_test_2.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\Danila\Documents\Лабы\Основы программирования\course\libs\data_structures\string\tasks\str_test_2.c" > CMakeFiles\course.dir\libs\data_structures\string\tasks\str_test_2.c.i

CMakeFiles/course.dir/libs/data_structures/string/tasks/str_test_2.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/course.dir/libs/data_structures/string/tasks/str_test_2.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\Danila\Documents\Лабы\Основы программирования\course\libs\data_structures\string\tasks\str_test_2.c" -o CMakeFiles\course.dir\libs\data_structures\string\tasks\str_test_2.c.s

CMakeFiles/course.dir/libs/data_structures/files/files.c.obj: CMakeFiles/course.dir/flags.make
CMakeFiles/course.dir/libs/data_structures/files/files.c.obj: C:/Users/Danila/Documents/Лабы/Основы\ программирования/course/libs/data_structures/files/files.c
CMakeFiles/course.dir/libs/data_structures/files/files.c.obj: CMakeFiles/course.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="C:\Users\Danila\Documents\Лабы\Основы программирования\course\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/course.dir/libs/data_structures/files/files.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/course.dir/libs/data_structures/files/files.c.obj -MF CMakeFiles\course.dir\libs\data_structures\files\files.c.obj.d -o CMakeFiles\course.dir\libs\data_structures\files\files.c.obj -c "C:\Users\Danila\Documents\Лабы\Основы программирования\course\libs\data_structures\files\files.c"

CMakeFiles/course.dir/libs/data_structures/files/files.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/course.dir/libs/data_structures/files/files.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\Danila\Documents\Лабы\Основы программирования\course\libs\data_structures\files\files.c" > CMakeFiles\course.dir\libs\data_structures\files\files.c.i

CMakeFiles/course.dir/libs/data_structures/files/files.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/course.dir/libs/data_structures/files/files.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\Danila\Documents\Лабы\Основы программирования\course\libs\data_structures\files\files.c" -o CMakeFiles\course.dir\libs\data_structures\files\files.c.s

# Object files for target course
course_OBJECTS = \
"CMakeFiles/course.dir/main.c.obj" \
"CMakeFiles/course.dir/vec.c.obj" \
"CMakeFiles/course.dir/vecV.c.obj" \
"CMakeFiles/course.dir/matrix_test.c.obj" \
"CMakeFiles/course.dir/matrix_ex.c.obj" \
"CMakeFiles/course.dir/libs/data_structures/string/tasks/str_test.c.obj" \
"CMakeFiles/course.dir/libs/data_structures/string/tasks/str_test_2.c.obj" \
"CMakeFiles/course.dir/libs/data_structures/files/files.c.obj"

# External object files for target course
course_EXTERNAL_OBJECTS =

course.exe: CMakeFiles/course.dir/main.c.obj
course.exe: CMakeFiles/course.dir/vec.c.obj
course.exe: CMakeFiles/course.dir/vecV.c.obj
course.exe: CMakeFiles/course.dir/matrix_test.c.obj
course.exe: CMakeFiles/course.dir/matrix_ex.c.obj
course.exe: CMakeFiles/course.dir/libs/data_structures/string/tasks/str_test.c.obj
course.exe: CMakeFiles/course.dir/libs/data_structures/string/tasks/str_test_2.c.obj
course.exe: CMakeFiles/course.dir/libs/data_structures/files/files.c.obj
course.exe: CMakeFiles/course.dir/build.make
course.exe: libs/data_structures/libdata_structures.a
course.exe: libs/algorithms/libalgorithms.a
course.exe: libs/util/libutil.a
course.exe: CMakeFiles/course.dir/linkLibs.rsp
course.exe: CMakeFiles/course.dir/objects1.rsp
course.exe: CMakeFiles/course.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="C:\Users\Danila\Documents\Лабы\Основы программирования\course\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_9) "Linking C executable course.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\course.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/course.dir/build: course.exe
.PHONY : CMakeFiles/course.dir/build

CMakeFiles/course.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\course.dir\cmake_clean.cmake
.PHONY : CMakeFiles/course.dir/clean

CMakeFiles/course.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Danila\Documents\Лабы\Основы программирования\course" "C:\Users\Danila\Documents\Лабы\Основы программирования\course" "C:\Users\Danila\Documents\Лабы\Основы программирования\course\build" "C:\Users\Danila\Documents\Лабы\Основы программирования\course\build" "C:\Users\Danila\Documents\Лабы\Основы программирования\course\build\CMakeFiles\course.dir\DependInfo.cmake" "--color=$(COLOR)"
.PHONY : CMakeFiles/course.dir/depend

