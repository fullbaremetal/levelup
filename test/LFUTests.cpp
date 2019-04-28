#include <gtest/gtest.h>
#include "../src/amazon/LFU.hpp"

TEST(LFUTests, SimpleTest){
    LFUCache c(2);
    c.put(1, 1);
    c.put(2, 2);
    ASSERT_EQ(c.get(1), 1);
    c.put(3, 3);
    ASSERT_EQ(c.get(2), -1);
    ASSERT_EQ(c.get(3), 3);
    c.put(4, 4);
    ASSERT_EQ(c.get(1), -1);
    ASSERT_EQ(c.get(3), 3);
    ASSERT_EQ(c.get(4), 4);
}