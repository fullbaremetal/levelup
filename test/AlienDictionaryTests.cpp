#include <gtest/gtest.h>

#include "../src/airbnb/AlienDictionary.hpp"

TEST(AlienDictionaryTests, SimpleTest) {
    AlienDictionary a;
    string order=a.alienOrder({ "wrt","wrf","er","ett","rftt"});
    ASSERT_EQ(order, "wertf");
}

TEST(AlienDictionaryTests, AnotherTest) {
    AlienDictionary a;
    string order=a.alienOrder({ "za", "zb", "ca", "cb"});
    ASSERT_EQ(order, "abzc");
}

TEST(AlienDictionaryTests, NotAllVisited) {
    AlienDictionary a;
    string order=a.alienOrder({"ri","xz","qxf","jhsguaw","dztqrbwbm","dhdqfb","jdv","fcgfsilnb","ooby"});
    ASSERT_EQ(order, "");
}