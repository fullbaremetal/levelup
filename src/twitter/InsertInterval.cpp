#include<map>

#include "InsertInterval.hpp"

vector<Interval>  InsertInterval::insert(vector<Interval>& intervals, Interval newInterval) {
    map<int,int> m;
    for(auto e:intervals) m[e.start]=e.end;
    auto cmp = [](Interval i1, Interval i2){return i1.start<i2.start;};
    int s =newInterval.start, e=newInterval.end;
    auto l=m.upper_bound(s);
    auto r=m.upper_bound(e);
    
    if(l!=m.begin()) {
        l--;
        if(l->second<s) l++;
    }
    while(l!=r) {
        s=min(s, l->first);
        e=max(e, l->second);
        l=m.erase(l);
    }
    m[s]=e;
    vector<Interval>ans;
    for(auto e:m) ans.push_back(Interval(e.first, e.second));
    return ans;
}