#include <gtest/gtest.h>

#include "../src/airbnb/FileSystem.hpp"


TEST(FileSystemTests, PutAndGetNoError) {
    FileSystem fs;
    fs.put("/a", 10);
    fs.put("/a/b", 11);
    fs.put("/c", 1);
    fs.put("/c/c", 2);
    fs.put("/c/c/b", 3);
    fs.put("/c/b", 4);
    EXPECT_EQ(fs.get("/a"), 10);
    EXPECT_EQ(fs.get("/a/b"), 11);
    EXPECT_EQ(fs.get("/c"), 1);
    EXPECT_EQ(fs.get("/c/c"), 2);
    EXPECT_EQ(fs.get("/c/c/b"), 3);
    EXPECT_EQ(fs.get("/c/b"), 4);
}