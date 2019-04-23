#include<map>
#include<list>
#include<string>
#include<vector>

using namespace std;

class ReconstructItenary {
    map<string, list<string>> g;
    bool dfs(string cur, list<string>& ans, int n);
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets);
};