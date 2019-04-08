#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../src/airbnb/EmployeeFreeTime.hpp"

TEST(EmployeeFreeTimeTests, SimpleTest) {
    EmployeeFreeTime eft;
    ASSERT_THAT(eft.employeeFreeTime({{{1,2}, {5,6}, {1,3}, {4,10}}}), ::testing::ElementsAre(Interval(3,4)));
}