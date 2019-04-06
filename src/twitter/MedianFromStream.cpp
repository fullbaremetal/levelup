#include "MedianFromStream.hpp"

void MedianFinder::addNum(int num) {
    if(l.size()==0) {
        l.push(num);
        return;
    }
    int m=l.top();
    if(num<=m) l.push(num);
    else r.push(num);
    if(r.size()>l.size()) {
        l.push(r.top() );
        r.pop();
    }
    else if(l.size()>r.size()+1){
        r.push(l.top());
        l.pop();
    }
}

double MedianFinder::findMedian() {
    if(l.size()==r.size()) return (l.top()+r.top())/2.0;
    return l.top();
}