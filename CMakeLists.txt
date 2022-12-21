cmake_minimum_required(VERSION 3.0.0)

# Setup project
project(NaiveECS VERSION 0.0.1)
set(CMAKE_CXX_STANDARD 17)

add_executable(NaiveECS
    System.cpp
    Main.cpp
    World.cpp)