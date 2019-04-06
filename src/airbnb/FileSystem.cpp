#include "FileSystem.hpp"
#include <sstream>
#include <iostream>

Node::Node(int v) {
    val=v;
}

FileSystem::FileSystem() {
    root=new Node(0);
}

vector<string> FileSystem::tokenize(string input) {
    istringstream iss(input);
    vector<string> ans;
    string token;
    while(getline(iss, token, '/')) {
        if(token.length()==0) continue;
        ans.push_back(token);
    }
    return ans;
}

Node* travel(Node* cur, vector<string> tokens) {
    for(auto s:tokens) {
        if(cur==nullptr) return nullptr;
        cur=cur->next[s];
    }
    return cur;
}

void FileSystem::put(string path, int val) {
    vector<string> tokens = tokenize(path);
    if(tokens.size()==0)return;
    string last=tokens[tokens.size()-1];
    tokens.erase(tokens.begin()+(tokens.size()-1));
    for(auto e:tokens)cout<<e<<endl;
    Node* cur =travel(root, tokens);
    if(cur==nullptr) throw "path not found";
    if(cur->next.find(last)==cur->next.end()) cur->next[last]=new Node(val);
    else cur->next[last]->val=val;
}

int FileSystem::get(string path) {
    vector<string> tokens = tokenize(path);
    auto cur=travel(root, tokens);
    if(cur==nullptr) throw "path not found";
    return cur->val;
}