cmake_minimum_required(VERSION 3.7)
project(Parkhaus)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Stellplatz.cpp Parkhaus.cpp)
add_executable(Parkhaus ${SOURCE_FILES})