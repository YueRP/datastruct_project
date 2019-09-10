cmake_minimum_required(VERSION 3.14)
project(MILP)
set(CMAKE_CXX_STANDARD 14)

add_executable(${PROJECT_NAME}  graph.cpp graph.h main.cpp)
