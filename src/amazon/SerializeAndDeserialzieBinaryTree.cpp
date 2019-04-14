#include <iostream>
#include <sstream>
#include <vector>

#include "SerializeAndDeserialzieBinaryTree.hpp"


TreeNode* construct(istringstream& in) {
        string val;
        in>>val;
        if(val=="$") return nullptr;
        TreeNode* root=new TreeNode(stoi(val));
        root->left=construct(in);
        root->right=construct(in);
        return root;
    }
    void serializeHelper(TreeNode* root, ostringstream& out) {
        if(root==nullptr) {
            out<<"$ ";
        } else {
            out<<root->val<<" ";
            serializeHelper(root->left, out);
            serializeHelper(root->right, out);
        }
    }
string BinaryTreeCodec::serialize(TreeNode* root) {
    ostringstream out;
    serializeHelper(root, out);
    return out.str();
}

// Decodes your encoded data to tree.
TreeNode* BinaryTreeCodec::deserialize(string data) {
    istringstream in(data);
    return construct(in);
}