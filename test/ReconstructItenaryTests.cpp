#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../src/linkedin/ReconstructItenary.hpp"

TEST(ReconstructItenaryTests, LCTEST) {
    ReconstructItenary r;
    auto ans=r.findItinerary({{"INN","CBR"},{"AXA","ADL"},{"HBA","SYD"},{"CBR","INN"},{"AUA","MEL"},{"CBR","ADL"},{"PER","LST"},{"OOL","HBA"},{"LST","SYD"},{"EZE","LST"},{"HBA","EZE"},{"MEL","LST"},{"INN","CNS"},{"ADL","INN"},{"BNE","MEL"},{"AXA","CBR"},{"CNS","OOL"},{"LST","AXA"},{"AXA","CBR"},{"HBA","CBR"},{"JFK","EZE"},{"AUA","EZE"},{"CBR","AXA"},{"LST","BNE"},{"AUA","BIM"},{"AUA","MEL"},{"CBR","HBA"},{"AXA","LST"},{"PER","ANU"},{"ANU","AUA"},{"SYD","PER"},{"MEL","PER"},{"CBR","MEL"},{"BNE","AUA"},{"LST","CBR"},{"EZE","AUA"},{"LST","PER"},{"MEL","BNE"},{"PER","AXA"},{"EZE","HBA"},{"MEL","AUA"},{"SYD","AXA"},{"ADL","LST"}});
    ASSERT_THAT(ans, ::testing::ElementsAre("JFK","EZE","AUA","EZE","HBA","CBR","ADL","INN","CBR","AXA","ADL","LST","AXA","CBR","HBA","EZE","LST","BNE","AUA","MEL","AUA","MEL","BNE","MEL","LST","CBR","INN","CNS","OOL","HBA","SYD","AXA","CBR","MEL","PER","AXA","LST","PER","LST","SYD","PER","ANU","AUA","BIM"));
}

TEST(ReconstructItenaryTests, LCTEST2) {
    ReconstructItenary r;
    auto ans=r.findItinerary({{"MEL","PER"},{"SYD","CBR"},{"AUA","DRW"},{"JFK","EZE"},{"PER","AXA"},{"DRW","AUA"},{"EZE","SYD"},{"AUA","MEL"},{"DRW","AUA"},{"PER","ANU"},{"CBR","EZE"},{"EZE","PER"},{"MEL","EZE"},{"EZE","MEL"},{"EZE","TBI"},{"ADL","DRW"},{"ANU","EZE"},{"AXA","ADL"}});
    ASSERT_THAT(ans, ::testing::ElementsAre("JFK","EZE","MEL","EZE","PER","AXA","ADL","DRW","AUA","DRW","AUA","MEL","PER","ANU","EZE","SYD","CBR","EZE","TBI"));
}