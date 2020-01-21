#include <gtest/gtest.h>

#include "../src/google/ContainerWithMostWater.hpp"

TEST(ContainerWithMostWaterTests, SimpleTest){
	ContainerWithMostWater c;
	vector<int> v= {1, 8 , 6, 2, 5, 4, 8, 3, 7};
	ASSERT_EQ(c.maxArea(v), 49);
}
