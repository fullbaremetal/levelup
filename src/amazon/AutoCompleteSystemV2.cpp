#include "AutoCompleteSystemV2.hpp"

void acsv2::insert(Node *root, string word, int times) {
    Node* cur=root;
    for(auto c:word){
        if(cur->next.find(c)==cur->next.end()) cur->next[c]=new Node();
        cur=cur->next[c];
        cur->m[times].insert(word);
    }
}

void AutocompleteSystemV2::inc(string word) {
    if(timesm.find(word)==timesm.end()) {
        acsv2::insert(root, word, 1);
        timesm[word]=1;
        return;
    }
    acsv2::Node* cur=root;
    int times=timesm[word];
    for(auto c:word) {
        cur=cur->next[c];
        cur->m[times].erase(word);
        if(cur->m[times].empty()) cur->m.erase(times);
        cur->m[times+1].insert(word);
    }
    timesm[word]++;
}

AutocompleteSystemV2::AutocompleteSystemV2(vector<string>& sentences, vector<int>& times) {
    root=new acsv2::Node();
    for(int i=0;i<sentences.size();i++) {
        acsv2::insert(root, sentences[i], times[i]);
        timesm[sentences[i]]=times[i];
    }
    curNode=root;
}

vector<string> AutocompleteSystemV2::input(char c) {
    vector<string> res;
    if(c=='#') {
        if(!curSentence.empty()) inc(curSentence);
        curSentence="";
        curNode=root;
        return res;
    }
    curSentence+=c;
    if(curNode==nullptr) return res;
    if(curNode->next.find(c)==curNode->next.end()){
        curNode=nullptr;
        return res;
    }
    curNode=curNode->next[c];
    for(auto it=curNode->m.rbegin();it!=curNode->m.rend();it++) {
        for(auto w:it->second) {
            res.push_back(w);
            if(res.size()==3) return res;
        }
    }
    return res;
}