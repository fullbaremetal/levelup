#include<sstream>
#include<algorithm>
#include "FileSystemNew.hpp"


vector<string> tokenize(string path) {
    vector<string> tokens;
    istringstream iss(path);
    string token;
    while(getline(iss, token, '/')) {
        if(token.length()==0) continue;
        tokens.push_back(token);
    }
    return tokens;
}
FileSystemNew::FileSystemNew() {
    root=new node();
}

vector<string> FileSystemNew::ls(string path){
    auto cur=root;
    vector<string> ans;
    auto bc= tokenize(path);
    if(bc.size()!=0) {
        for(int i=0;i<bc.size()-1;i++) {
            if(cur==nullptr) return ans;
            cur=cur->dirs[bc[i]];
        }
        if(cur->files.find(bc.back())!= cur->files.end()) return {bc.back()};
        cur=cur->dirs[bc.back()];
    }
    for(auto e:cur->files) ans.push_back(e.first);
    for(auto e:cur->dirs) ans.push_back(e.first);
    sort(ans.begin(), ans.end());
    return ans;
}
    
void FileSystemNew::mkdir(string path) {
    auto cur=root;
    for(auto e:tokenize(path)) {
        if(cur->dirs.find(e)==cur->dirs.end()) 
            cur->dirs[e]=new node();
        cur=cur->dirs[e];
    }
}
    
void FileSystemNew::addContentToFile(string filePath, string content){
    auto cur=root;
    auto bc= tokenize(filePath);
    if(bc.size()==0) return;
    for(int i=0;i<bc.size()-1;i++) {
        cur=cur->dirs[bc[i]];
        if(cur==nullptr) return;
    }
    cur->files[bc.back()]+=content;
}
    
string FileSystemNew::readContentFromFile(string filePath){
    auto cur=root;
    auto bc= tokenize(filePath);
    if(bc.size()==0) return "";
    for(int i=0;i<bc.size()-1;i++) {
        if(cur==nullptr) return "";
        cur=cur->dirs[bc[i]];
    }
    if(cur->files.find(bc.back())==cur->files.end()) return "";
    return cur->files[bc.back()];
}
