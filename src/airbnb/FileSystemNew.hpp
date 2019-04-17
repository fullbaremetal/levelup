#include<vector>
#include<string>
#include<map>

using namespace std;

class node{
public:    
    map<string, string> files;
    map<string,node*> dirs;
};

class FileSystemNew {
private:    
    node* root;
public:
    FileSystemNew();
    vector<string> ls(string path);
    
    void mkdir(string path);
    
    void addContentToFile(string filePath, string content);
    
    string readContentFromFile(string filePath);
};