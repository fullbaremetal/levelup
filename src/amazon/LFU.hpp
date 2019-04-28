#include <unordered_map>
#include <list>

using namespace std;
class LFUCache {
private:    
    unordered_map<int, pair<int,int>> m;
    unordered_map<int, list<int>::iterator> lm;
    unordered_map<int, list<int>> fm;
    int capacity;
    int minFreq;
public:
    LFUCache(int capacity);
    
    int get(int key);
    
    void put(int key, int value);
};