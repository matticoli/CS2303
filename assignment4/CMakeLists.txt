cmake_minimum_required(VERSION 3.9)
project(assignment4)

set(CMAKE_CXX_STANDARD 11)

add_executable(assignment4 main.cpp Event.cpp Event.h EventQueue.cpp EventQueue.h TellerEvent.cpp TellerEvent.h CustomerEvent.cpp CustomerEvent.h CustomerQueue.cpp CustomerQueue.h)