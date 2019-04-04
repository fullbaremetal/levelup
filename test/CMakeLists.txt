cmake_minimum_required(VERSION 3.10)

set(This leveluptests)

set(Sources
    DisplayPageTests.cpp
    FileSystemTests.cpp
)

add_executable(${This} ${Sources})
target_link_libraries(${This} PUBLIC
    gtest_main
    gmock
    airbnb
)

add_test(
    NAME ${This}
    COMMAND ${This}
)