# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.19

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


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

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.3.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.3.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\tubor\Desktop\Facultate\Data Structures\data-structures-course\Lab3"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\tubor\Desktop\Facultate\Data Structures\data-structures-course\Lab3\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles\Lab3.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\Lab3.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\Lab3.dir\flags.make

CMakeFiles\Lab3.dir\App.cpp.obj: CMakeFiles\Lab3.dir\flags.make
CMakeFiles\Lab3.dir\App.cpp.obj: ..\App.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\tubor\Desktop\Facultate\Data Structures\data-structures-course\Lab3\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Lab3.dir/App.cpp.obj"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\Lab3.dir\App.cpp.obj /FdCMakeFiles\Lab3.dir\ /FS -c "C:\Users\tubor\Desktop\Facultate\Data Structures\data-structures-course\Lab3\App.cpp"
<<

CMakeFiles\Lab3.dir\App.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lab3.dir/App.cpp.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe > CMakeFiles\Lab3.dir\App.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\tubor\Desktop\Facultate\Data Structures\data-structures-course\Lab3\App.cpp"
<<

CMakeFiles\Lab3.dir\App.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lab3.dir/App.cpp.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\Lab3.dir\App.cpp.s /c "C:\Users\tubor\Desktop\Facultate\Data Structures\data-structures-course\Lab3\App.cpp"
<<

CMakeFiles\Lab3.dir\ShortTest.cpp.obj: CMakeFiles\Lab3.dir\flags.make
CMakeFiles\Lab3.dir\ShortTest.cpp.obj: ..\ShortTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\tubor\Desktop\Facultate\Data Structures\data-structures-course\Lab3\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Lab3.dir/ShortTest.cpp.obj"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\Lab3.dir\ShortTest.cpp.obj /FdCMakeFiles\Lab3.dir\ /FS -c "C:\Users\tubor\Desktop\Facultate\Data Structures\data-structures-course\Lab3\ShortTest.cpp"
<<

CMakeFiles\Lab3.dir\ShortTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lab3.dir/ShortTest.cpp.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe > CMakeFiles\Lab3.dir\ShortTest.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\tubor\Desktop\Facultate\Data Structures\data-structures-course\Lab3\ShortTest.cpp"
<<

CMakeFiles\Lab3.dir\ShortTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lab3.dir/ShortTest.cpp.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\Lab3.dir\ShortTest.cpp.s /c "C:\Users\tubor\Desktop\Facultate\Data Structures\data-structures-course\Lab3\ShortTest.cpp"
<<

CMakeFiles\Lab3.dir\ExtendedTest.cpp.obj: CMakeFiles\Lab3.dir\flags.make
CMakeFiles\Lab3.dir\ExtendedTest.cpp.obj: ..\ExtendedTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\tubor\Desktop\Facultate\Data Structures\data-structures-course\Lab3\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Lab3.dir/ExtendedTest.cpp.obj"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\Lab3.dir\ExtendedTest.cpp.obj /FdCMakeFiles\Lab3.dir\ /FS -c "C:\Users\tubor\Desktop\Facultate\Data Structures\data-structures-course\Lab3\ExtendedTest.cpp"
<<

CMakeFiles\Lab3.dir\ExtendedTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lab3.dir/ExtendedTest.cpp.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe > CMakeFiles\Lab3.dir\ExtendedTest.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\tubor\Desktop\Facultate\Data Structures\data-structures-course\Lab3\ExtendedTest.cpp"
<<

CMakeFiles\Lab3.dir\ExtendedTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lab3.dir/ExtendedTest.cpp.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\Lab3.dir\ExtendedTest.cpp.s /c "C:\Users\tubor\Desktop\Facultate\Data Structures\data-structures-course\Lab3\ExtendedTest.cpp"
<<

CMakeFiles\Lab3.dir\ListIterator.cpp.obj: CMakeFiles\Lab3.dir\flags.make
CMakeFiles\Lab3.dir\ListIterator.cpp.obj: ..\ListIterator.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\tubor\Desktop\Facultate\Data Structures\data-structures-course\Lab3\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Lab3.dir/ListIterator.cpp.obj"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\Lab3.dir\ListIterator.cpp.obj /FdCMakeFiles\Lab3.dir\ /FS -c "C:\Users\tubor\Desktop\Facultate\Data Structures\data-structures-course\Lab3\ListIterator.cpp"
<<

CMakeFiles\Lab3.dir\ListIterator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lab3.dir/ListIterator.cpp.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe > CMakeFiles\Lab3.dir\ListIterator.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\tubor\Desktop\Facultate\Data Structures\data-structures-course\Lab3\ListIterator.cpp"
<<

CMakeFiles\Lab3.dir\ListIterator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lab3.dir/ListIterator.cpp.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\Lab3.dir\ListIterator.cpp.s /c "C:\Users\tubor\Desktop\Facultate\Data Structures\data-structures-course\Lab3\ListIterator.cpp"
<<

CMakeFiles\Lab3.dir\IndexedList.cpp.obj: CMakeFiles\Lab3.dir\flags.make
CMakeFiles\Lab3.dir\IndexedList.cpp.obj: ..\IndexedList.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\tubor\Desktop\Facultate\Data Structures\data-structures-course\Lab3\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Lab3.dir/IndexedList.cpp.obj"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\Lab3.dir\IndexedList.cpp.obj /FdCMakeFiles\Lab3.dir\ /FS -c "C:\Users\tubor\Desktop\Facultate\Data Structures\data-structures-course\Lab3\IndexedList.cpp"
<<

CMakeFiles\Lab3.dir\IndexedList.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lab3.dir/IndexedList.cpp.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe > CMakeFiles\Lab3.dir\IndexedList.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\tubor\Desktop\Facultate\Data Structures\data-structures-course\Lab3\IndexedList.cpp"
<<

CMakeFiles\Lab3.dir\IndexedList.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lab3.dir/IndexedList.cpp.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\Lab3.dir\IndexedList.cpp.s /c "C:\Users\tubor\Desktop\Facultate\Data Structures\data-structures-course\Lab3\IndexedList.cpp"
<<

# Object files for target Lab3
Lab3_OBJECTS = \
"CMakeFiles\Lab3.dir\App.cpp.obj" \
"CMakeFiles\Lab3.dir\ShortTest.cpp.obj" \
"CMakeFiles\Lab3.dir\ExtendedTest.cpp.obj" \
"CMakeFiles\Lab3.dir\ListIterator.cpp.obj" \
"CMakeFiles\Lab3.dir\IndexedList.cpp.obj"

# External object files for target Lab3
Lab3_EXTERNAL_OBJECTS =

Lab3.exe: CMakeFiles\Lab3.dir\App.cpp.obj
Lab3.exe: CMakeFiles\Lab3.dir\ShortTest.cpp.obj
Lab3.exe: CMakeFiles\Lab3.dir\ExtendedTest.cpp.obj
Lab3.exe: CMakeFiles\Lab3.dir\ListIterator.cpp.obj
Lab3.exe: CMakeFiles\Lab3.dir\IndexedList.cpp.obj
Lab3.exe: CMakeFiles\Lab3.dir\build.make
Lab3.exe: CMakeFiles\Lab3.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\tubor\Desktop\Facultate\Data Structures\data-structures-course\Lab3\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable Lab3.exe"
	"C:\Program Files\JetBrains\CLion 2020.3.3\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\Lab3.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x86\mt.exe --manifests -- C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\Lab3.dir\objects1.rsp @<<
 /out:Lab3.exe /implib:Lab3.lib /pdb:"C:\Users\tubor\Desktop\Facultate\Data Structures\data-structures-course\Lab3\cmake-build-debug\Lab3.pdb" /version:0.0 /machine:X86 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\Lab3.dir\build: Lab3.exe

.PHONY : CMakeFiles\Lab3.dir\build

CMakeFiles\Lab3.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Lab3.dir\cmake_clean.cmake
.PHONY : CMakeFiles\Lab3.dir\clean

CMakeFiles\Lab3.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" "C:\Users\tubor\Desktop\Facultate\Data Structures\data-structures-course\Lab3" "C:\Users\tubor\Desktop\Facultate\Data Structures\data-structures-course\Lab3" "C:\Users\tubor\Desktop\Facultate\Data Structures\data-structures-course\Lab3\cmake-build-debug" "C:\Users\tubor\Desktop\Facultate\Data Structures\data-structures-course\Lab3\cmake-build-debug" "C:\Users\tubor\Desktop\Facultate\Data Structures\data-structures-course\Lab3\cmake-build-debug\CMakeFiles\Lab3.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles\Lab3.dir\depend

