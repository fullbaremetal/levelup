#include<iostream>
#include<vector>
#include<list>
#include<set>

using namespace std;

string id(string e) {
    return e.substr( 0, e.find_first_of(","));
}

vector<vector<string>> displayPage(vector<string> entries, int pageSize) {
    vector<vector<string>> pages;
    list<string> l(entries.begin(), entries.end());
    while(!l.empty()) {
        set<string> seen;
        vector<string> page;
        for(auto it=l.begin();it!=l.end() && page.size()<pageSize;) {
            if(seen.find(id(*it))!=seen.end()) it++;
            else {
                seen.insert(id(*it));
                page.push_back(*it);
                it=l.erase(it);
            }
        }
        pages.push_back(page);
    }
    return pages;
}
