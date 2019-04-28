#include "LFU.hpp"

LFUCache::LFUCache(int cap) {
    capacity=cap;
    minFreq=1;
}

int LFUCache::get(int key) {
    if(m.find(key)==m.end()) return -1;
    int freq=m[key].second;
    fm[freq].erase(lm[key]);
    if(fm[freq].empty()) {
        fm.erase(freq);
        if(freq==minFreq) minFreq=freq+1;
    }
    m[key].second++, freq++;
    fm[freq].push_front(key);
    lm[key]=fm[freq].begin();
    return m[key].first;
}

void LFUCache::put(int key, int value){
    if(m.find(key)==m.end() && m.size()==capacity) {
        // evict lfu
        int lfuKey = fm[minFreq].back();
        fm[minFreq].pop_back();
        if(fm[minFreq].empty()) fm.erase(minFreq++);
        lm.erase(lfuKey);
        m.erase(lfuKey);
    }
    if(m.find(key)!=m.end()) {
        m[key].first=value;
        get(key);
        return;
    }
    minFreq=1;
    fm[minFreq].push_front(key);
    lm[key]=fm[minFreq].begin();
    m[key]={value, minFreq};
}