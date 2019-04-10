#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../src/amazon/AutoCompleteSystem.hpp"

TEST(AutoCompleteSystemTests, simpleTest) {
    AutocompleteSystem as({"i love you", "island","ironman", "i love leetcode"}, {5,3,2,2});
    ASSERT_THAT(as.input('i'), testing::ElementsAre("i love you", "island", "i love leetcode"));
    ASSERT_THAT(as.input(' '), testing::ElementsAre("i love you", "i love leetcode"));
    ASSERT_THAT(as.input('a'), testing::ElementsAre());
    ASSERT_THAT(as.input('b'), testing::ElementsAre());
    ASSERT_THAT(as.input('#'), testing::ElementsAre());
    ASSERT_THAT(as.input('i'), testing::ElementsAre("i love you", "island", "i love leetcode"));
    ASSERT_THAT(as.input(' '), testing::ElementsAre("i love you", "i love leetcode", "i ab"));
    ASSERT_THAT(as.input('a'), testing::ElementsAre("i ab"));
    ASSERT_THAT(as.input('b'), testing::ElementsAre("i ab"));
    ASSERT_THAT(as.input('#'), testing::ElementsAre());
    ASSERT_THAT(as.input('i'), testing::ElementsAre("i love you", "island", "i ab"));
    ASSERT_THAT(as.input(' '), testing::ElementsAre("i love you", "i ab", "i love leetcode"));
    ASSERT_THAT(as.input('l'), testing::ElementsAre("i love you", "i love leetcode"));
    ASSERT_THAT(as.input('o'), testing::ElementsAre("i love you", "i love leetcode"));
    ASSERT_THAT(as.input('v'), testing::ElementsAre("i love you", "i love leetcode"));
    ASSERT_THAT(as.input('e'), testing::ElementsAre("i love you", "i love leetcode"));
    ASSERT_THAT(as.input('#'), testing::ElementsAre());
    ASSERT_THAT(as.input('#'), testing::ElementsAre());
    ASSERT_THAT(as.input('i'), testing::ElementsAre("i love you", "island", "i ab"));
    ASSERT_THAT(as.input(' '), testing::ElementsAre("i love you", "i ab", "i love leetcode"));
    ASSERT_THAT(as.input('l'), testing::ElementsAre("i love you", "i love leetcode", "i love"));
}