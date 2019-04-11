#include<vector>
#include<list>

using namespace std;
class Queue{
private:    
    int size;
    list<pair<vector<int>, int>> l;
public:
    Queue(int size);
    int front();
    void pop();
    void push(int x);
};