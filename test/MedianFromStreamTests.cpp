#include <gtest/gtest.h>

#include "../src/twitter/MedianFromStream.hpp"

TEST(MedianFromStreamTests, simpletest) {
    MedianFinder mf;
    mf.addNum(5);
    ASSERT_EQ(mf.findMedian(), 5);
    mf.addNum(8);
    ASSERT_EQ(mf.findMedian(), 6.5);
    mf.addNum(2);
    ASSERT_EQ(mf.findMedian(), 5);
    mf.addNum(3);
    ASSERT_EQ(mf.findMedian(), 4);
    mf.addNum(1);
    ASSERT_EQ(mf.findMedian(), 3);
}