#include<string>
#include<vector>
#include<map>

using namespace std;

class LogStorage{
private:
    map<string,vector<int>> m;
    map<string,int> gm={{"Year", 0}, {"Month", 1}, {"Day", 2}, {"Hour", 3}, {"Minute", 4}, {"Second", 5}};
    string truncateByGranularity(string time, string pad, string gra);
public:
    void put(int id, string timestamp);
    vector<int> retrieve(string s, string e, string gra);
};
