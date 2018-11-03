cmake_minimum_required(VERSION 3.12)
project(CVamp)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(CVamp
        main.cpp
        Resume.cpp
        Resume.h)
