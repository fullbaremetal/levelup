cmake_minimum_required(VERSION 3.10)

set(This leveluptests)

set(Sources
    DisplayPageTests.cpp
    FileSystemTests.cpp
    LogStorageTests.cpp
    MedianFromStreamTests.cpp
    InsertIntervalTests.cpp
    AlienDictionaryTests.cpp
    CheapestFlightWithInKStopsTests.cpp
    IPToCIDRTests.cpp
    EmployeeFreeTimeTests.cpp
    AutoCompleteSystemTests.cpp
    QueueWithFixedArraysTests.cpp
    CutoffTreesForGolfEventTests.cpp
    MaxFreqStackTests.cpp
    SerializeAndDeserialzieBinaryTreeTests.cpp
    FindMedianInLargeFileTests.cpp
    FileSystemNewTests.cpp
    AllOneDSTests.cpp
    ReconstructItenaryTests.cpp
)

add_executable(${This} ${Sources})
target_link_libraries(${This} PUBLIC
    gtest_main
    gmock
    airbnb
    twitter
    amazon
    linkedin
)

add_test(
    NAME ${This}
    COMMAND ${This}
)