#include <gtest/gtest.h>

#include "../src/airbnb/QueueWithFixedArrays.hpp"

TEST(QueueWithFixedArraysTests, SimpleTest) {
    Queue q(2);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    ASSERT_EQ(q.front(), 1);
    q.pop();
    ASSERT_EQ(q.front(), 2);
    q.pop();
    ASSERT_EQ(q.front(), 3);
    q.pop();
    ASSERT_EQ(q.front(), 4);
}