cmake_minimum_required(VERSION 3.17)
project(EdmondsKarp)

set(CMAKE_CXX_STANDARD 17)

add_executable(EdmondsKarp main.cpp Algorithm.cpp Algorithm.h Graph.cpp Graph.h)