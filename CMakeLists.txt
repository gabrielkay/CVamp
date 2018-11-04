cmake_minimum_required(VERSION 3.12)
project(CVamp)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(CVamp
        main.cpp
        Resume.cpp
        Resume.h)
