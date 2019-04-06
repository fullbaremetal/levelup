#include<string>
#include<map>
#include<set>
#include<iostream>

#include "AlienDictionary.hpp"

void dfs(char c, string& word, set<char>& vis, map<char, int>& in, map<char, vector<char>>& g) {
    word=word+c;
    vis.insert(c);
    for(auto e:g[c]) {
        in[e]--;
        if(vis.find(e)!=vis.end() || in[e]>0) continue;
        dfs(e, word, vis, in, g);
    }
}

string AlienDictionary::alienOrder(vector<string> words) {
    map<char,vector<char>> g;
    map<char, int> in;
    for(int i=0;i<words.size();i++) {
        for(auto c:words[i]) if(g.find(c)==g.end()) g[c]=vector<char>();
        if(i==words.size()-1)continue;
        for(int j=0;j<words[i].size() && j<words[i+1].size();j++) {
            if(words[i][j]==words[i+1][j]) continue;
            cout<<words[i][j]<<" "<<words[i+1][j]<<endl;
            g[words[i][j]].push_back(words[i+1][j]);
            in[words[i+1][j]]++;
            break;
        }
    }
    set<char> vis;
    string ans="";
    for(auto e:g) {
        if(vis.find(e.first)!=vis.end() || in[e.first]>0) continue;
        dfs(e.first, ans, vis, in, g);
    }
    return vis.size()==g.size()?ans:"";
}