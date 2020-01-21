#include "ContainerWithMostWater.hpp"
#include <algorithm>

int ContainerWithMostWater::maxArea(vector<int>& v) {
	int l=0, r=v.size()-1;
	int ans = 0;
	int area;
	while(l <  r) {
		area = min(v[l], v[r]) * (r-l);
		if(area > ans) ans = area;
		if(v[l] < v[r]) l++;
		else r--;
	}
	return ans;
}
