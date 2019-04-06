#include<vector>

using namespace std;


class Interval {
public:
    bool operator==(const Interval &i) const {
        return start==i.start&&end==i.end;
    }
    Interval(int s, int e){
        start=s,end=e;
    }
    int start,end;
};

class InsertInterval {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval);
};