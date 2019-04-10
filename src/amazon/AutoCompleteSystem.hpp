#include<vector>
#include<string>
#include<queue>
#include<map>

using namespace std;

typedef pair<int, string> pis;

struct comp {
    bool operator()(pis p1, pis p2) {
        if(p1.first!=p2.first) return p1.first<p2.first;
        return p1.second>p2.second;
    }
};

class Node{
public:
    Node();
    map<char,Node*> next;
    int times;
    string str;
};

class Trie{
    Node* root;
    Node* cur;
    string query;
public:
    Trie();
    void print(Node* c);
    void insert(string s, int times);
    vector<string> advance(char c);
};

class AutocompleteSystem {
    Trie t;
public:
    AutocompleteSystem(vector<string> sentences, vector<int> times);
    vector<string> input(char c);
};