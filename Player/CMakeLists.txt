cmake_minimum_required(VERSION 3.21)
project(Player)

set(CMAKE_CXX_STANDARD 23)
include_directories(include)
set(SOURCE_FILES
        src/player.cpp)
add_executable(Player ${SOURCE_FILES} main.cpp)
