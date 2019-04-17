#include<gtest/gtest.h>
#include<gmock/gmock.h>

#include "../src/airbnb/FileSystemNew.hpp"

TEST(FileSystemNewTests, SimpleTest) {
    FileSystemNew fs;
    ASSERT_EQ(fs.ls("/").size(), 0);
    fs.mkdir("/a/b/c");
    ASSERT_THAT(fs.ls("/"), testing::ElementsAre("a"));
    ASSERT_THAT(fs.ls("/a"), testing::ElementsAre("b"));
    ASSERT_THAT(fs.ls("/a/b"), testing::ElementsAre("c"));
    fs.addContentToFile("/a/b/c/d", "dcontent");
    ASSERT_EQ(fs.readContentFromFile("/a/b/c/d"), "dcontent");
    fs.addContentToFile("/a/b/e", "econtent");
    ASSERT_EQ(fs.readContentFromFile("/a/b/e"), "econtent");
}

TEST(FileSystemNewTests, Test2) {
    FileSystemNew fs;
    ASSERT_EQ(fs.ls("/").size(), 0);
    fs.mkdir("/goowmfn");
    ASSERT_EQ(fs.ls("/goowmfn").size(), 0);
    ASSERT_THAT(fs.ls("/"), testing::ElementsAre("goowmfn"));
    fs.mkdir("/z");
    ASSERT_THAT(fs.ls("/"), testing::ElementsAre("goowmfn", "z"));
    fs.addContentToFile("/goowmfn/c", "shetopcy");
    ASSERT_EQ(fs.ls("/z").size(), 0);
    ASSERT_THAT(fs.ls("/goowmfn/c"), testing::ElementsAre("c"));
    ASSERT_THAT(fs.ls("/goowmfn"), testing::ElementsAre("c"));
    fs.addContentToFile("/goowmfn/c", "2");
    ASSERT_EQ(fs.readContentFromFile("/goowmfn/c"), "shetopcy2");
}