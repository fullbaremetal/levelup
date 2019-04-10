#include "AutoCompleteSystem.hpp"
#include<iostream>

Node::Node() {
    times=0;
    str="";
}
Trie::Trie() {
    root=new Node();
    cur=root;
    query="";
}

void Trie::insert(string s, int times) {
    Node* c=root;
    for(int i=0;i<s.length();i++) {
        if(c->next.find(s[i])==c->next.end()) c->next[s[i]]=new Node();
        c=c->next[s[i]];
    }
    c->times+=times;
    c->str=s;
}

void dfs(Node* cur, priority_queue<pis, vector<pis>, comp>& pq) {
    if(cur->str!="") pq.push({cur->times,cur->str});
    for(auto& e:cur->next) dfs(e.second, pq);
}

vector<string> Trie::advance(char c) {
    if(c=='#') {
        insert(query, 1);
        query="";
        cur=root;
        return {};
    }
    query+=c;
    if(!cur || cur->next.find(c)==cur->next.end()) {
        cur=nullptr;
        return {};
    }
    cur=cur->next[c];
    vector<string> ans;
    priority_queue<pis, vector<pis>, comp> pq;
    dfs(cur, pq);
    while(!pq.empty() && ans.size()<3) {
        ans.push_back(pq.top().second);
        pq.pop();
    }
    return ans;
}
AutocompleteSystem::AutocompleteSystem(vector<string> sentences, vector<int> times) {
    for(int i=0;i<sentences.size();i++) t.insert(sentences[i],times[i]);
}
vector<string> AutocompleteSystem::input(char c) {
    return t.advance(c);
}