#include<set>
#include "ReconstructItenary.hpp"

bool ReconstructItenary:: dfs(string cur, list<string>& ans, int n) {
    if(g.find(cur)==g.end() || g[cur].empty()) return ans.size()==n;
    auto it=g[cur].begin();
    while(it!=g[cur].end()) {
        string next=*it;
        it=g[cur].erase(it);
        ans.push_back(next);
        if(dfs(next, ans,n)) return true;
        ans.pop_back();
        it=g[cur].insert(it,next);
        it++;
    }
    return false;
}

vector<string> ReconstructItenary:: findItinerary(vector<pair<string, string>> tickets) {
    map<string, multiset<string>> tg;
    for(auto t:tickets) tg[t.first].insert(t.second);
    for(auto& e:tg) g[e.first]=list<string>(e.second.begin(), e.second.end());
    list<string> ans;
    ans.push_back("JFK");
    dfs("JFK", ans,tickets.size()+1);
    return vector<string>(ans.begin(), ans.end());
}