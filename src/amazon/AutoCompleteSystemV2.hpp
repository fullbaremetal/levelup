#include<vector>
#include<string>
#include <map>
#include <set>


using namespace std;


namespace acsv2 {
    class Node {
    public:        
        map<char, Node*> next;
        map<int,  set<string>>m;
    };
    void insert(Node* root, string word, int times);
    void inc(Node* root, string word);
}

class AutocompleteSystemV2 {
private:
    map<string, int> timesm;    
    acsv2::Node* root;
    acsv2::Node* curNode;
    string curSentence;
    void inc(string word);
public:
    AutocompleteSystemV2(vector<string>& sentences, vector<int>& times);
    
    vector<string> input(char c);
};