#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../src/twitter/LogStorage.hpp"

TEST(LogStorageTests, SimplePutAndGet) {
    LogStorage l;
    l.put(1, "2017:01:01:23:59:59");
    l.put(2, "2017:01:01:22:59:59");
    l.put(3, "2016:01:01:00:00:00");
    ASSERT_THAT(l.retrieve("2016:01:01:01:01:01","2017:01:01:23:00:00","Year"), ::testing::ElementsAre(1,2,3));
    ASSERT_THAT(l.retrieve("2016:01:01:01:01:01","2017:01:01:23:00:00","Hour"), ::testing::ElementsAre(1,2));
    ASSERT_THAT(l.retrieve("2016:01:01:01:01:01","2017:01:01:23:00:00","Second"), ::testing::ElementsAre(2));
}