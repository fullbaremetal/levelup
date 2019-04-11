#include<iostream>
#include "QueueWithFixedArrays.hpp"

Queue::Queue(int size) {
    this->size=size;
    l.push_back({vector<int>(),0});
}

void Queue::push(int x) {
    if(l.back().first.size()==size) l.push_back({vector<int>(), 0});
    l.back().first.push_back(x);
}

void Queue::pop() {
    auto idx =l.front().second;
    if(idx==l.front().first.size()-1) {
        l.front().first.clear();
        l.pop_front();
    } else l.front().second++;
}

int Queue::front() {
    return l.front().first[l.front().second];
}