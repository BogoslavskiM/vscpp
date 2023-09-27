cmake_minimum_required(VERSION 3.26)
project(Testing)

set(CMAKE_CXX_STANDARD 17)

add_executable(Testing my_files/main.cpp
        my_files/hello_fun.cpp)
