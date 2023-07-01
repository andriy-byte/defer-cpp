cmake_minimum_required(VERSION 3.25)
project(test CXX)
set(CMAKE_CXX_STANDARD 23)

add_executable(test main.cpp ../include/defer.hpp)
