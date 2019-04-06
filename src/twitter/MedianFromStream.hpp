#include<vector>
#include<queue>
using namespace std;
class MedianFinder {
    priority_queue<int> l;
    priority_queue<int, vector<int>, greater<int>> r;
public:
    void addNum(int num);
    double findMedian();
};
