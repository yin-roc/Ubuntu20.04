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
CMAKE_SOURCE_DIR = /home/yin-roc/1_Code/Ubuntu20.04/Workspace/baidu_map_ws/src/baidu_map

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/yin-roc/1_Code/Ubuntu20.04/Workspace/baidu_map_ws/build/baidu_map

# Utility rule file for baidu_map_qmlimportscan.

# Include the progress variables for this target.
include CMakeFiles/baidu_map_qmlimportscan.dir/progress.make

CMakeFiles/baidu_map_qmlimportscan: .qt_plugins/Qt6_QmlPlugins_Imports_baidu_map.cmake


.qt_plugins/Qt6_QmlPlugins_Imports_baidu_map.cmake: /home/yin-roc/Qt6.6/6.6.2/gcc_64/libexec/qmlimportscanner
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/yin-roc/1_Code/Ubuntu20.04/Workspace/baidu_map_ws/build/baidu_map/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Running qmlimportscanner for baidu_map"
	cd /home/yin-roc/1_Code/Ubuntu20.04/Workspace/baidu_map_ws/src/baidu_map && /home/yin-roc/Qt6.6/6.6.2/gcc_64/libexec/qmlimportscanner @/home/yin-roc/1_Code/Ubuntu20.04/Workspace/baidu_map_ws/build/baidu_map/.qt_plugins/Qt6_QmlPlugins_Imports_baidu_map.rsp

baidu_map_qmlimportscan: CMakeFiles/baidu_map_qmlimportscan
baidu_map_qmlimportscan: .qt_plugins/Qt6_QmlPlugins_Imports_baidu_map.cmake
baidu_map_qmlimportscan: CMakeFiles/baidu_map_qmlimportscan.dir/build.make

.PHONY : baidu_map_qmlimportscan

# Rule to build all files generated by this target.
CMakeFiles/baidu_map_qmlimportscan.dir/build: baidu_map_qmlimportscan

.PHONY : CMakeFiles/baidu_map_qmlimportscan.dir/build

CMakeFiles/baidu_map_qmlimportscan.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/baidu_map_qmlimportscan.dir/cmake_clean.cmake
.PHONY : CMakeFiles/baidu_map_qmlimportscan.dir/clean

CMakeFiles/baidu_map_qmlimportscan.dir/depend:
	cd /home/yin-roc/1_Code/Ubuntu20.04/Workspace/baidu_map_ws/build/baidu_map && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/yin-roc/1_Code/Ubuntu20.04/Workspace/baidu_map_ws/src/baidu_map /home/yin-roc/1_Code/Ubuntu20.04/Workspace/baidu_map_ws/src/baidu_map /home/yin-roc/1_Code/Ubuntu20.04/Workspace/baidu_map_ws/build/baidu_map /home/yin-roc/1_Code/Ubuntu20.04/Workspace/baidu_map_ws/build/baidu_map /home/yin-roc/1_Code/Ubuntu20.04/Workspace/baidu_map_ws/build/baidu_map/CMakeFiles/baidu_map_qmlimportscan.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/baidu_map_qmlimportscan.dir/depend
