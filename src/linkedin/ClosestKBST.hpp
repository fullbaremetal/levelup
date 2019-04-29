#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x):val(x),left(nullptr), right(nullptr){}
};

class ClosestKBST {
public:
    vector<int> closestKValues(TreeNode* root, double target, int k);
};