#include <gtest/gtest.h>
#include "../src/linkedin/AllOneDS.hpp"

TEST(AllOneDSTests,SimpleTests) {
    AllOne a;
    ASSERT_EQ(a.getMaxKey(), "");
    a.inc("abc");
    ASSERT_EQ(a.getMaxKey(), "abc");
    a.inc("abc");
    ASSERT_EQ(a.getMaxKey(), "abc");
    a.inc("abd");
    ASSERT_EQ(a.getMaxKey(), "abc");
    ASSERT_EQ(a.getMinKey(), "abd");
    a.dec("abc");
    a.dec("abc");
    ASSERT_EQ(a.getMaxKey(), "abd");
    ASSERT_EQ(a.getMinKey(), "abd");
    a.dec("abd");
    ASSERT_EQ(a.getMaxKey(), "");
    ASSERT_EQ(a.getMinKey(), "");
}

TEST(AllOneDSTests,LCTests) {
    AllOne a;
    a.inc("hello");
    a.inc("hello");
    ASSERT_EQ(a.getMaxKey(), "hello");
    cout<<"here"<<endl;
    ASSERT_EQ(a.getMinKey(), "hello");
    cout<<"here"<<endl;
    a.inc("leet");
    cout<<"here"<<endl;
    ASSERT_EQ(a.getMaxKey(), "hello");
    cout<<"here"<<endl;
    ASSERT_EQ(a.getMinKey(), "leet");
}