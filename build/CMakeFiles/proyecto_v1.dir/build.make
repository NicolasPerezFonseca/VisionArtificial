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
CMAKE_SOURCE_DIR = "/home/sistemas/Documentos/Vision Artificial/Proyecto V1"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/sistemas/Documentos/Vision Artificial/Proyecto V1/build"

# Include any dependencies generated for this target.
include CMakeFiles/proyecto_v1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/proyecto_v1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/proyecto_v1.dir/flags.make

CMakeFiles/proyecto_v1.dir/proyecto_v1.cxx.o: CMakeFiles/proyecto_v1.dir/flags.make
CMakeFiles/proyecto_v1.dir/proyecto_v1.cxx.o: ../proyecto_v1.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/sistemas/Documentos/Vision Artificial/Proyecto V1/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/proyecto_v1.dir/proyecto_v1.cxx.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/proyecto_v1.dir/proyecto_v1.cxx.o -c "/home/sistemas/Documentos/Vision Artificial/Proyecto V1/proyecto_v1.cxx"

CMakeFiles/proyecto_v1.dir/proyecto_v1.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/proyecto_v1.dir/proyecto_v1.cxx.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/sistemas/Documentos/Vision Artificial/Proyecto V1/proyecto_v1.cxx" > CMakeFiles/proyecto_v1.dir/proyecto_v1.cxx.i

CMakeFiles/proyecto_v1.dir/proyecto_v1.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/proyecto_v1.dir/proyecto_v1.cxx.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/sistemas/Documentos/Vision Artificial/Proyecto V1/proyecto_v1.cxx" -o CMakeFiles/proyecto_v1.dir/proyecto_v1.cxx.s

# Object files for target proyecto_v1
proyecto_v1_OBJECTS = \
"CMakeFiles/proyecto_v1.dir/proyecto_v1.cxx.o"

# External object files for target proyecto_v1
proyecto_v1_EXTERNAL_OBJECTS =

proyecto_v1: CMakeFiles/proyecto_v1.dir/proyecto_v1.cxx.o
proyecto_v1: CMakeFiles/proyecto_v1.dir/build.make
proyecto_v1: /usr/local/lib/libopencv_gapi.so.4.5.1
proyecto_v1: /usr/local/lib/libopencv_highgui.so.4.5.1
proyecto_v1: /usr/local/lib/libopencv_ml.so.4.5.1
proyecto_v1: /usr/local/lib/libopencv_objdetect.so.4.5.1
proyecto_v1: /usr/local/lib/libopencv_photo.so.4.5.1
proyecto_v1: /usr/local/lib/libopencv_stitching.so.4.5.1
proyecto_v1: /usr/local/lib/libopencv_video.so.4.5.1
proyecto_v1: /usr/local/lib/libopencv_videoio.so.4.5.1
proyecto_v1: /usr/local/lib/libopencv_dnn.so.4.5.1
proyecto_v1: /usr/local/lib/libopencv_imgcodecs.so.4.5.1
proyecto_v1: /usr/local/lib/libopencv_calib3d.so.4.5.1
proyecto_v1: /usr/local/lib/libopencv_features2d.so.4.5.1
proyecto_v1: /usr/local/lib/libopencv_flann.so.4.5.1
proyecto_v1: /usr/local/lib/libopencv_imgproc.so.4.5.1
proyecto_v1: /usr/local/lib/libopencv_core.so.4.5.1
proyecto_v1: CMakeFiles/proyecto_v1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/sistemas/Documentos/Vision Artificial/Proyecto V1/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable proyecto_v1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/proyecto_v1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/proyecto_v1.dir/build: proyecto_v1

.PHONY : CMakeFiles/proyecto_v1.dir/build

CMakeFiles/proyecto_v1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/proyecto_v1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/proyecto_v1.dir/clean

CMakeFiles/proyecto_v1.dir/depend:
	cd "/home/sistemas/Documentos/Vision Artificial/Proyecto V1/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/sistemas/Documentos/Vision Artificial/Proyecto V1" "/home/sistemas/Documentos/Vision Artificial/Proyecto V1" "/home/sistemas/Documentos/Vision Artificial/Proyecto V1/build" "/home/sistemas/Documentos/Vision Artificial/Proyecto V1/build" "/home/sistemas/Documentos/Vision Artificial/Proyecto V1/build/CMakeFiles/proyecto_v1.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/proyecto_v1.dir/depend

