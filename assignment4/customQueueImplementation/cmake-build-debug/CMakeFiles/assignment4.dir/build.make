# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = /opt/clion/bin/cmake/bin/cmake

# The command to remove a file.
RM = /opt/clion/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/student/CS2303/assignment4/customQueueImplementation

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/student/CS2303/assignment4/customQueueImplementation/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/assignment4.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/assignment4.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/assignment4.dir/flags.make

CMakeFiles/assignment4.dir/main.cpp.o: CMakeFiles/assignment4.dir/flags.make
CMakeFiles/assignment4.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/student/CS2303/assignment4/customQueueImplementation/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/assignment4.dir/main.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/assignment4.dir/main.cpp.o -c /home/student/CS2303/assignment4/customQueueImplementation/main.cpp

CMakeFiles/assignment4.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/assignment4.dir/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/student/CS2303/assignment4/customQueueImplementation/main.cpp > CMakeFiles/assignment4.dir/main.cpp.i

CMakeFiles/assignment4.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/assignment4.dir/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/student/CS2303/assignment4/customQueueImplementation/main.cpp -o CMakeFiles/assignment4.dir/main.cpp.s

CMakeFiles/assignment4.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/assignment4.dir/main.cpp.o.requires

CMakeFiles/assignment4.dir/main.cpp.o.provides: CMakeFiles/assignment4.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/assignment4.dir/build.make CMakeFiles/assignment4.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/assignment4.dir/main.cpp.o.provides

CMakeFiles/assignment4.dir/main.cpp.o.provides.build: CMakeFiles/assignment4.dir/main.cpp.o


CMakeFiles/assignment4.dir/Event.cpp.o: CMakeFiles/assignment4.dir/flags.make
CMakeFiles/assignment4.dir/Event.cpp.o: ../Event.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/student/CS2303/assignment4/customQueueImplementation/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/assignment4.dir/Event.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/assignment4.dir/Event.cpp.o -c /home/student/CS2303/assignment4/customQueueImplementation/Event.cpp

CMakeFiles/assignment4.dir/Event.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/assignment4.dir/Event.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/student/CS2303/assignment4/customQueueImplementation/Event.cpp > CMakeFiles/assignment4.dir/Event.cpp.i

CMakeFiles/assignment4.dir/Event.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/assignment4.dir/Event.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/student/CS2303/assignment4/customQueueImplementation/Event.cpp -o CMakeFiles/assignment4.dir/Event.cpp.s

CMakeFiles/assignment4.dir/Event.cpp.o.requires:

.PHONY : CMakeFiles/assignment4.dir/Event.cpp.o.requires

CMakeFiles/assignment4.dir/Event.cpp.o.provides: CMakeFiles/assignment4.dir/Event.cpp.o.requires
	$(MAKE) -f CMakeFiles/assignment4.dir/build.make CMakeFiles/assignment4.dir/Event.cpp.o.provides.build
.PHONY : CMakeFiles/assignment4.dir/Event.cpp.o.provides

CMakeFiles/assignment4.dir/Event.cpp.o.provides.build: CMakeFiles/assignment4.dir/Event.cpp.o


CMakeFiles/assignment4.dir/EventQueue.cpp.o: CMakeFiles/assignment4.dir/flags.make
CMakeFiles/assignment4.dir/EventQueue.cpp.o: ../EventQueue.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/student/CS2303/assignment4/customQueueImplementation/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/assignment4.dir/EventQueue.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/assignment4.dir/EventQueue.cpp.o -c /home/student/CS2303/assignment4/customQueueImplementation/EventQueue.cpp

CMakeFiles/assignment4.dir/EventQueue.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/assignment4.dir/EventQueue.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/student/CS2303/assignment4/customQueueImplementation/EventQueue.cpp > CMakeFiles/assignment4.dir/EventQueue.cpp.i

CMakeFiles/assignment4.dir/EventQueue.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/assignment4.dir/EventQueue.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/student/CS2303/assignment4/customQueueImplementation/EventQueue.cpp -o CMakeFiles/assignment4.dir/EventQueue.cpp.s

CMakeFiles/assignment4.dir/EventQueue.cpp.o.requires:

.PHONY : CMakeFiles/assignment4.dir/EventQueue.cpp.o.requires

CMakeFiles/assignment4.dir/EventQueue.cpp.o.provides: CMakeFiles/assignment4.dir/EventQueue.cpp.o.requires
	$(MAKE) -f CMakeFiles/assignment4.dir/build.make CMakeFiles/assignment4.dir/EventQueue.cpp.o.provides.build
.PHONY : CMakeFiles/assignment4.dir/EventQueue.cpp.o.provides

CMakeFiles/assignment4.dir/EventQueue.cpp.o.provides.build: CMakeFiles/assignment4.dir/EventQueue.cpp.o


CMakeFiles/assignment4.dir/TellerEvent.cpp.o: CMakeFiles/assignment4.dir/flags.make
CMakeFiles/assignment4.dir/TellerEvent.cpp.o: ../TellerEvent.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/student/CS2303/assignment4/customQueueImplementation/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/assignment4.dir/TellerEvent.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/assignment4.dir/TellerEvent.cpp.o -c /home/student/CS2303/assignment4/customQueueImplementation/TellerEvent.cpp

CMakeFiles/assignment4.dir/TellerEvent.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/assignment4.dir/TellerEvent.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/student/CS2303/assignment4/customQueueImplementation/TellerEvent.cpp > CMakeFiles/assignment4.dir/TellerEvent.cpp.i

CMakeFiles/assignment4.dir/TellerEvent.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/assignment4.dir/TellerEvent.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/student/CS2303/assignment4/customQueueImplementation/TellerEvent.cpp -o CMakeFiles/assignment4.dir/TellerEvent.cpp.s

CMakeFiles/assignment4.dir/TellerEvent.cpp.o.requires:

.PHONY : CMakeFiles/assignment4.dir/TellerEvent.cpp.o.requires

CMakeFiles/assignment4.dir/TellerEvent.cpp.o.provides: CMakeFiles/assignment4.dir/TellerEvent.cpp.o.requires
	$(MAKE) -f CMakeFiles/assignment4.dir/build.make CMakeFiles/assignment4.dir/TellerEvent.cpp.o.provides.build
.PHONY : CMakeFiles/assignment4.dir/TellerEvent.cpp.o.provides

CMakeFiles/assignment4.dir/TellerEvent.cpp.o.provides.build: CMakeFiles/assignment4.dir/TellerEvent.cpp.o


CMakeFiles/assignment4.dir/CustomerEvent.cpp.o: CMakeFiles/assignment4.dir/flags.make
CMakeFiles/assignment4.dir/CustomerEvent.cpp.o: ../CustomerEvent.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/student/CS2303/assignment4/customQueueImplementation/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/assignment4.dir/CustomerEvent.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/assignment4.dir/CustomerEvent.cpp.o -c /home/student/CS2303/assignment4/customQueueImplementation/CustomerEvent.cpp

CMakeFiles/assignment4.dir/CustomerEvent.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/assignment4.dir/CustomerEvent.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/student/CS2303/assignment4/customQueueImplementation/CustomerEvent.cpp > CMakeFiles/assignment4.dir/CustomerEvent.cpp.i

CMakeFiles/assignment4.dir/CustomerEvent.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/assignment4.dir/CustomerEvent.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/student/CS2303/assignment4/customQueueImplementation/CustomerEvent.cpp -o CMakeFiles/assignment4.dir/CustomerEvent.cpp.s

CMakeFiles/assignment4.dir/CustomerEvent.cpp.o.requires:

.PHONY : CMakeFiles/assignment4.dir/CustomerEvent.cpp.o.requires

CMakeFiles/assignment4.dir/CustomerEvent.cpp.o.provides: CMakeFiles/assignment4.dir/CustomerEvent.cpp.o.requires
	$(MAKE) -f CMakeFiles/assignment4.dir/build.make CMakeFiles/assignment4.dir/CustomerEvent.cpp.o.provides.build
.PHONY : CMakeFiles/assignment4.dir/CustomerEvent.cpp.o.provides

CMakeFiles/assignment4.dir/CustomerEvent.cpp.o.provides.build: CMakeFiles/assignment4.dir/CustomerEvent.cpp.o


CMakeFiles/assignment4.dir/TellerQueue.cpp.o: CMakeFiles/assignment4.dir/flags.make
CMakeFiles/assignment4.dir/TellerQueue.cpp.o: ../TellerQueue.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/student/CS2303/assignment4/customQueueImplementation/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/assignment4.dir/TellerQueue.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/assignment4.dir/TellerQueue.cpp.o -c /home/student/CS2303/assignment4/customQueueImplementation/TellerQueue.cpp

CMakeFiles/assignment4.dir/TellerQueue.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/assignment4.dir/TellerQueue.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/student/CS2303/assignment4/customQueueImplementation/TellerQueue.cpp > CMakeFiles/assignment4.dir/TellerQueue.cpp.i

CMakeFiles/assignment4.dir/TellerQueue.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/assignment4.dir/TellerQueue.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/student/CS2303/assignment4/customQueueImplementation/TellerQueue.cpp -o CMakeFiles/assignment4.dir/TellerQueue.cpp.s

CMakeFiles/assignment4.dir/TellerQueue.cpp.o.requires:

.PHONY : CMakeFiles/assignment4.dir/TellerQueue.cpp.o.requires

CMakeFiles/assignment4.dir/TellerQueue.cpp.o.provides: CMakeFiles/assignment4.dir/TellerQueue.cpp.o.requires
	$(MAKE) -f CMakeFiles/assignment4.dir/build.make CMakeFiles/assignment4.dir/TellerQueue.cpp.o.provides.build
.PHONY : CMakeFiles/assignment4.dir/TellerQueue.cpp.o.provides

CMakeFiles/assignment4.dir/TellerQueue.cpp.o.provides.build: CMakeFiles/assignment4.dir/TellerQueue.cpp.o


CMakeFiles/assignment4.dir/SortedEventQueue.cpp.o: CMakeFiles/assignment4.dir/flags.make
CMakeFiles/assignment4.dir/SortedEventQueue.cpp.o: ../SortedEventQueue.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/student/CS2303/assignment4/customQueueImplementation/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/assignment4.dir/SortedEventQueue.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/assignment4.dir/SortedEventQueue.cpp.o -c /home/student/CS2303/assignment4/customQueueImplementation/SortedEventQueue.cpp

CMakeFiles/assignment4.dir/SortedEventQueue.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/assignment4.dir/SortedEventQueue.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/student/CS2303/assignment4/customQueueImplementation/SortedEventQueue.cpp > CMakeFiles/assignment4.dir/SortedEventQueue.cpp.i

CMakeFiles/assignment4.dir/SortedEventQueue.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/assignment4.dir/SortedEventQueue.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/student/CS2303/assignment4/customQueueImplementation/SortedEventQueue.cpp -o CMakeFiles/assignment4.dir/SortedEventQueue.cpp.s

CMakeFiles/assignment4.dir/SortedEventQueue.cpp.o.requires:

.PHONY : CMakeFiles/assignment4.dir/SortedEventQueue.cpp.o.requires

CMakeFiles/assignment4.dir/SortedEventQueue.cpp.o.provides: CMakeFiles/assignment4.dir/SortedEventQueue.cpp.o.requires
	$(MAKE) -f CMakeFiles/assignment4.dir/build.make CMakeFiles/assignment4.dir/SortedEventQueue.cpp.o.provides.build
.PHONY : CMakeFiles/assignment4.dir/SortedEventQueue.cpp.o.provides

CMakeFiles/assignment4.dir/SortedEventQueue.cpp.o.provides.build: CMakeFiles/assignment4.dir/SortedEventQueue.cpp.o


# Object files for target assignment4
assignment4_OBJECTS = \
"CMakeFiles/assignment4.dir/main.cpp.o" \
"CMakeFiles/assignment4.dir/Event.cpp.o" \
"CMakeFiles/assignment4.dir/EventQueue.cpp.o" \
"CMakeFiles/assignment4.dir/TellerEvent.cpp.o" \
"CMakeFiles/assignment4.dir/CustomerEvent.cpp.o" \
"CMakeFiles/assignment4.dir/TellerQueue.cpp.o" \
"CMakeFiles/assignment4.dir/SortedEventQueue.cpp.o"

# External object files for target assignment4
assignment4_EXTERNAL_OBJECTS =

assignment4: CMakeFiles/assignment4.dir/main.cpp.o
assignment4: CMakeFiles/assignment4.dir/Event.cpp.o
assignment4: CMakeFiles/assignment4.dir/EventQueue.cpp.o
assignment4: CMakeFiles/assignment4.dir/TellerEvent.cpp.o
assignment4: CMakeFiles/assignment4.dir/CustomerEvent.cpp.o
assignment4: CMakeFiles/assignment4.dir/TellerQueue.cpp.o
assignment4: CMakeFiles/assignment4.dir/SortedEventQueue.cpp.o
assignment4: CMakeFiles/assignment4.dir/build.make
assignment4: CMakeFiles/assignment4.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/student/CS2303/assignment4/customQueueImplementation/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable assignment4"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/assignment4.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/assignment4.dir/build: assignment4

.PHONY : CMakeFiles/assignment4.dir/build

CMakeFiles/assignment4.dir/requires: CMakeFiles/assignment4.dir/main.cpp.o.requires
CMakeFiles/assignment4.dir/requires: CMakeFiles/assignment4.dir/Event.cpp.o.requires
CMakeFiles/assignment4.dir/requires: CMakeFiles/assignment4.dir/EventQueue.cpp.o.requires
CMakeFiles/assignment4.dir/requires: CMakeFiles/assignment4.dir/TellerEvent.cpp.o.requires
CMakeFiles/assignment4.dir/requires: CMakeFiles/assignment4.dir/CustomerEvent.cpp.o.requires
CMakeFiles/assignment4.dir/requires: CMakeFiles/assignment4.dir/TellerQueue.cpp.o.requires
CMakeFiles/assignment4.dir/requires: CMakeFiles/assignment4.dir/SortedEventQueue.cpp.o.requires

.PHONY : CMakeFiles/assignment4.dir/requires

CMakeFiles/assignment4.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/assignment4.dir/cmake_clean.cmake
.PHONY : CMakeFiles/assignment4.dir/clean

CMakeFiles/assignment4.dir/depend:
	cd /home/student/CS2303/assignment4/customQueueImplementation/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/student/CS2303/assignment4/customQueueImplementation /home/student/CS2303/assignment4/customQueueImplementation /home/student/CS2303/assignment4/customQueueImplementation/cmake-build-debug /home/student/CS2303/assignment4/customQueueImplementation/cmake-build-debug /home/student/CS2303/assignment4/customQueueImplementation/cmake-build-debug/CMakeFiles/assignment4.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/assignment4.dir/depend
