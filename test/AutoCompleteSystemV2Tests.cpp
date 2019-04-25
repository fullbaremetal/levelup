#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../src/amazon/AutoCompleteSystemV2.hpp"

TEST(AutoCompleteSystemV2Tests, SimpleTest) {
    vector<string> sentences = {"i love you", "island","ironman","i love leetcode"};
    vector<int> times = {5,3,2,2};
    AutocompleteSystemV2 a(sentences, times);
    ASSERT_THAT(a.input('i'), ::testing::ElementsAre("i love you", "island", "i love leetcode"));
    ASSERT_THAT(a.input(' '), ::testing::ElementsAre("i love you", "i love leetcode"));
    ASSERT_THAT(a.input('a'), ::testing::ElementsAre());
    ASSERT_THAT(a.input('#'), ::testing::ElementsAre());
    ASSERT_THAT(a.input('i'), ::testing::ElementsAre("i love you", "island", "i love leetcode"));
    ASSERT_THAT(a.input(' '), ::testing::ElementsAre("i love you", "i love leetcode", "i a"));
    ASSERT_THAT(a.input('a'), ::testing::ElementsAre("i a"));
    ASSERT_THAT(a.input('#'), ::testing::ElementsAre());
    ASSERT_THAT(a.input('i'), ::testing::ElementsAre("i love you", "island", "i a"));
    ASSERT_THAT(a.input(' '), ::testing::ElementsAre("i love you", "i a", "i love leetcode"));
}