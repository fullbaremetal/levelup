#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../src/twitter/InsertInterval.hpp"

TEST(InsertIntervalTests, SimpleTest) {
    InsertInterval i;
    vector<Interval> intervals={Interval(2,3), Interval(4,8)};
    auto actual=i.insert(intervals,Interval(3,4));
    ASSERT_THAT(actual, ::testing::ElementsAre(Interval(2,8)));
}

TEST(InsertIntervalTests, EmptyTest) {
    InsertInterval i;
    vector<Interval> intervals={};
    auto actual=i.insert(intervals,Interval(3,4));
    ASSERT_THAT(actual, ::testing::ElementsAre(Interval(3,4)));
}

TEST(InsertIntervalTests, NonOverlapping) {
    InsertInterval i;
    vector<Interval> intervals={Interval(4, 5)};
    auto actual=i.insert(intervals,Interval(1,3));
    ASSERT_THAT(actual, ::testing::ElementsAre(Interval(1,3), Interval(4,5)));
}


TEST(InsertIntervalTests, OverlappingMultiple) {
    InsertInterval i;
    vector<Interval> intervals={Interval(4, 5), Interval(7,10), Interval(15,20)};
    auto actual=i.insert(intervals,Interval(6, 27));
    ASSERT_THAT(actual, ::testing::ElementsAre(Interval(4,5), Interval(6,27)));
}