#include<map>
#include "EmployeeFreeTime.hpp"

vector<Interval> EmployeeFreeTime::employeeFreeTime(vector<vector<Interval>> schedule) {
    vector<Interval> ans;
    map<int, int> merged;
    for(auto e:schedule) {
        for(auto i:e) {
            auto l=merged.upper_bound(i.start);
            auto r=merged.upper_bound(i.end);
            int s=i.start, e=i.end;
            if(l!=merged.begin()) {
                l--;
                if(l->second<s) l++;
            }
            while(l!=r) {
                s=min(s, l->first);
                e=max(e, l->second);
                l=merged.erase(l);
            }
            merged[s]=e;
        }
    }
    for(auto it=merged.begin();it!=merged.end();it++) {
        auto n=next(it,1);
        if(n==merged.end()) break;
        ans.push_back({it->second, n->first});
    }
    return ans;
}