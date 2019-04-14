#include <gtest/gtest.h>

#include "../src/amazon/MaxFreqStack.hpp"

TEST(MaxFreqStack, SimpleTest) {
    FreqStack f;
    f.push(5);
    f.push(7);
    f.push(5);
    f.push(7);
    f.push(4);
    f.push(5);
    ASSERT_EQ(f.pop(), 5);
    ASSERT_EQ(f.pop(), 7);
    ASSERT_EQ(f.pop(), 5);
    ASSERT_EQ(f.pop(), 4);
    ASSERT_EQ(f.pop(), 7);
    ASSERT_EQ(f.pop(), 5);
}