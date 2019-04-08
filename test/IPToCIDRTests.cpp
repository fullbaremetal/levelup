#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../src/airbnb/IPToCIDR.hpp"

 TEST(IPToCIDRTests, SimpleTest) {
     IPToCIDR i;
     ASSERT_THAT(i.ipToCIDR("255.0.0.7", 10), ::testing::ElementsAre("255.0.0.7/32", "255.0.0.8/29", "255.0.0.16/32")); 
     ASSERT_THAT(i.ipToCIDR("255.0.0.0", 256), ::testing::ElementsAre("255.0.0.0/24"));
 }