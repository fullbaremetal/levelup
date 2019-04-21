#include<unordered_map>
#include<unordered_set>
#include<list>
#include<string>
using namespace std;

struct Bucket{
    int val;
    unordered_set<string> s;
    Bucket(int v){
        val=v;
    }
};

class AllOne {
    unordered_map<string, list<Bucket>::iterator> m;
    list<Bucket> l;
public:
    void inc(string key) {
        if(m.find(key)==m.end()) {
            if(l.empty() || l.front().val!=1) l.push_front(Bucket(1));
            l.front().s.insert(key);
            m[key]=l.begin();
            return;
        }
        auto it=m[key];
        it->s.erase(key);
        int newVal=it->val+1;
        if(it->s.empty()) it=l.erase(it);
        else it++;
        if(it==l.end() || it->val!=newVal) it=l.insert(it, Bucket(newVal));
        it->s.insert(key);
        m[key]=it;
    }
    
    void dec(string key) {
        if(m.find(key)==m.end()) return;
        auto it=m[key];
        it->s.erase(key);
        int newVal=it->val-1;
        if(it->s.empty()) it=l.erase(it);
        if(newVal==0) {
            m.erase(key);
            return;
        }
        if(it==l.begin() || prev(it)->val!=newVal) it=l.insert(it, Bucket(newVal));
        else it=prev(it);
        it->s.insert(key);
        m[key]=it;
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        if(l.empty()) return "";
        return *l.back().s.begin();
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        if(l.empty()) return "";
        return *l.front().s.begin();
    }
};