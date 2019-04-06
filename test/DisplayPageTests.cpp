#include <gtest/gtest.h>
#include <vector>
#include <gmock/gmock.h>

#include "../src/airbnb/DisplayPage.hpp"

TEST(DisplayPageTests, SimpleTest) {
    std::vector<std::string> entries = {
        "1,28,300.1,SanFrancisco",
        "29,22,2.1,SanJose",
        "28,22,2.1,SanJose",
        "29,22,2.1,SanJose",
        "1,5,209.1,SanFrancisco",
        "1,7,208.1,SanFrancisco"
    };
    auto pages=displayPage(entries,2);
    ASSERT_EQ(pages.size(), 4);
    ASSERT_THAT(pages[0], ::testing::ElementsAre("1,28,300.1,SanFrancisco","29,22,2.1,SanJose"));
    ASSERT_THAT(pages[1], ::testing::ElementsAre("28,22,2.1,SanJose", "29,22,2.1,SanJose"));
    ASSERT_THAT(pages[2], ::testing::ElementsAre("1,5,209.1,SanFrancisco"));
    ASSERT_THAT(pages[3], ::testing::ElementsAre("1,7,208.1,SanFrancisco"));
}