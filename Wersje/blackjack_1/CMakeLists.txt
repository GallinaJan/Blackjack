cmake_minimum_required(VERSION 3.22)

project(blackjack_1)

set(PROJECT_ID blackjack_1)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES
        src/player.cpp
        src/cleaning.cpp
        )

set(SOURCES_FILES_TESTS
        test/main_gtest.cpp
        )

include(../SetCommonConfig.cmake)

add_executable(blackjack_1 main.cpp)
