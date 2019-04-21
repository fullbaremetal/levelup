#include "FindMedianInLargeFile.hpp"
#include <climits>

int median(vector<int>& nums, int median) {
    int start= INT_MIN, end=INT_MAX;
    int count=0, guess=0, res=INT_MIN;
    while(start<=end) {
        guess=(start+end)/2;
        count=0;
        res=INT_MIN;
        for(auto num: nums) {
            if(num<=guess) {
                count++;
                res=max(res, num);
            }
        }
        if(count==median) return res;
        if(count<median) {
            start=max(res+1, guess);
        } else {
            end=res;
        }
    }
    return INT_MIN;
}

double FindMedianInLargeFile::FindMedian(vector<int>& nums) {
    int len=nums.size();
    if(len%2==1) return median(nums, len/2+1);
    return (median(nums, len/2)+median(nums, len/2+1))/2.0;
}