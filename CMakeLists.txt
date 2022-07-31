cmake_minimum_required(VERSION 3.16.3)
project(straustrup)

set(SOURCES src/main.cpp src/Vector.cpp)
include_directories("include/")

add_executable(straustrup ${SOURCES})