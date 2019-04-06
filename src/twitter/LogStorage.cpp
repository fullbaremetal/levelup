#include <sstream>
#include <iostream>
#include "LogStorage.hpp"

void LogStorage::put(int id, string timestamp){
    if(m.find(timestamp)==m.end()) m[timestamp]=vector<int>();
    m[timestamp].push_back(id);
}

string LogStorage::truncateByGranularity(string time, string pad, string gra){
    string ans;
    istringstream iss(time);
    string token;
    int c=0;
    while(getline(iss, token, ':')) {
        if(gm[gra]<c) ans=ans+pad;
        else ans=ans+token;
        ans=ans+":";
        c++;
    }
    return ans.substr(0, ans.length()-1);
}

vector<int> LogStorage::retrieve(string s, string e, string gra) {
    vector<int> ans;
    string ts=truncateByGranularity(s, "00", gra), te=truncateByGranularity(e, "99", gra);
    cout<<ts<<" "<<te<<endl;
    auto lb=m.lower_bound(ts), ub=m.upper_bound(te);
    if(ub!=m.end()) cout<<ub->first<<endl;
    for(auto it=lb;it!=ub;it++) for(auto e: it->second) ans.push_back(e);
    sort(ans.begin(), ans.end());
    return ans;
}