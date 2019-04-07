#include <gtest/gtest.h>

#include "../src/airbnb/CheapestFlightWithInKStops.hpp"

TEST(CheapestFlightWithInKStopsTests, SimpleTest) {
    CheapestFlightWithinKStops c;
    ASSERT_EQ(10, c.findCheapestPrice(5, {{0,1,2},{0,2,5},{1,3,3},{3,4,1},{2,4,5}}, 0, 4, 1));
    ASSERT_EQ(6, c.findCheapestPrice(4, {{0,1,1},{0,2,5},{1,2,1},{2,3,1}}, 0, 3, 1));
}
