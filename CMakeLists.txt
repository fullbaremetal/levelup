cmake_minimum_required(VERSION 3.10)

set(This levelup)

project(${This} C CXX)
set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

enable_testing()

add_subdirectory(googletest)

set(Sources
    DisplayPage.cpp
)

add_library(${This} STATIC ${Sources})

add_subdirectory(test)