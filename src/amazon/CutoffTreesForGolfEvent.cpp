#include "CutoffTreesForGolfEvent.hpp"
#include <queue>
#include <map>

vector<int> di={1,0,-1,0};
vector<int> dj={0,1,0,-1};
int bfs(int i1, int j1, int i2, int j2, vector<vector<int>>& forest) {
    queue<pair<int,int>> q;
    vector<vector<int>> d(forest.size(), vector<int>(forest[i1].size(), -1));
    q.push({i1,j1});
    d[i1][j1]=0;
    int ni,nj;
    while(!q.empty()) {
        auto cur=q.front();
        q.pop();
        if(cur.first==i2 && cur.second==j2) return d[i2][j2];
        for(int i=0;i<4;i++) {
            ni=cur.first+di[i];
            nj=cur.second+dj[i];
            if(ni<0||nj<0||ni>=forest.size()||nj>=forest[ni].size()||d[ni][nj]!=-1||forest[ni][nj]==0)
                continue;
            d[ni][nj]=d[cur.first][cur.second]+1;
            q.push({ni, nj});
        }
    }
    return -1;
}
int CutoffTreesForGolfEvent::cutOffTree(vector<vector<int>> forest) {
    map<int, pair<int,int>> m;
    for(int i=0;i<forest.size();i++)
        for(int j=0;j<forest[i].size();j++)
            if(forest[i][j]>1) m[forest[i][j]]={i,j};
    int i1=0,j1=0,i2,j2;
    int ans=0;
    int res;
    for(auto e:m) {
        i2=e.second.first;
        j2=e.second.second;
        res=bfs(i1,j1,i2,j2, forest);
        if(res==-1) return -1;
        ans+=res;
        i1=i2;
        j1=j2;
    }
    return ans;
}