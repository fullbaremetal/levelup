#include<string>
#include<map>
#include<vector>

using namespace std;

class Node {
public:
    Node(int val);
    int val;
    map<string,Node*> next;
};

class FileSystem {
private:
    Node* root;
    vector<string> tokenize(string intput);
public:
    FileSystem();
    void put(string path, int val);
    int get(string path);
};