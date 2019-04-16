#include <gtest/gtest.h>

#include "../src/airbnb/FindMedianInLargeFile.hpp"

TEST(FindMedianInLargeFileTests, TestOdd) {
    FindMedianInLargeFile f;
    vector<int> v={5, 8, 1, 9, 4};
    ASSERT_EQ(f.FindMedian(v), 5);
}

TEST(FindMedianInLargeFileTests, TestEven) {
    FindMedianInLargeFile f;
    vector<int> v={5, 8, 9, 4};
    ASSERT_EQ(f.FindMedian(v), 6.5);
}