cmake_minimum_required(VERSION 3.8)
project(Harley)

find_file(SDL2_INCLUDE_DIR NAME SDL.H HINTS SDL2)
find_library(SDL2_LIBRARY NAME SDL2)
add_executable(Harley main.cpp)
target_include_directories(Harley ${SDL2_INCLUDE_DIR})
target_link_libraries(Harley ${SDL2_LIBRARY})