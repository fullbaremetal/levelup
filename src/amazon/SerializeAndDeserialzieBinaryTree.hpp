#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) {
        val=x;
        left=nullptr;
        right=nullptr;
    }
};

class BinaryTreeCodec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root);
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data);
};