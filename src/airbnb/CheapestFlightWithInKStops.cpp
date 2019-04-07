#include<map>
#include<queue>
#include<climits>
#include "CheapestFlightWithInKStops.hpp"

typedef pair<int,int> pii;
typedef pair<int,pii> pip;

int CheapestFlightWithinKStops::findCheapestPrice(int n, vector<vector<int> > flights, int src, int dst, int K) {
    vector<int> stops(n, INT_MAX);
    map<int, vector<pii>> edges;
    for(auto e: flights) edges[e[0]].push_back({e[1], e[2]});
    priority_queue<pip, vector<pip>, greater<pip>> q;
    vector<bool> vis(n, false);
    q.push({0, {src, 0}});
    while(!q.empty()) {
        auto cur=q.top();
        q.pop();
        int curIdx=cur.second.first;
        int stops=cur.second.second;
        vis[curIdx]=true;
        if(curIdx==dst) return cur.first;
        if(stops>K) continue;
        for(auto next:edges[curIdx]) {
            if(vis[next.first])continue;
            q.push({cur.first+next.second, {next.first,stops+1}});
        }
    }
    return -1;
}