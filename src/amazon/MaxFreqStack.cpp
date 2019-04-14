#include "MaxFreqStack.hpp"
#include<iostream>

FreqStack::FreqStack() {
    mf=0;
}

void FreqStack::push(int x){
    cm[x]++;
    if(cm[x]>mf) mf=cm[x];
    rm[cm[x]].push_back(x);
}

int FreqStack::pop() {
    int x=rm[mf].back();
    rm[mf].pop_back();
    if(rm[mf].empty()) rm.erase(mf--);
    cm[x]--;
    return x;
}