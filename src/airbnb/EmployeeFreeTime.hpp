#include<vector>

using namespace std;

 struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
    bool operator==(const Interval& i) const {
        return i.start==start&&i.end==end;
    }
};

class EmployeeFreeTime{
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule);
};