#include<unordered_map>
#include<list>

using namespace std;
class FreqStack {
    unordered_map<int, int> cm;
    unordered_map<int, list<int>> rm;
    int mf;
public:
    FreqStack();
    void push(int x);
    int pop();
};