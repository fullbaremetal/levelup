#include <gtest/gtest.h>

#include "../src/amazon/SerializeAndDeserialzieBinaryTree.hpp"


bool treeEqual(TreeNode* t1, TreeNode* t2) {
    if(t1==nullptr && t2==nullptr) return true;
    if(t1==nullptr || t2==nullptr) return false;
    if(t1->val!=t2->val) return false;
    return treeEqual(t1->left, t2->left) && treeEqual(t1->right, t2->right);
}

TEST(SerializeAndDeserialzieBinaryTreeTests, SimpleTest) {
    BinaryTreeCodec c;
    TreeNode* root=new TreeNode(1);
    TreeNode* lr=new TreeNode(2);
    TreeNode* rr=new TreeNode(3);
    TreeNode* lrr=new TreeNode(4);
    root->left=lr;
    root->right=rr;
    rr->left=lrr;
    ASSERT_EQ(c.serialize(root), "1 2 $ $ 3 4 $ $ $ ");
    ASSERT_TRUE(treeEqual(root, c.deserialize(c.serialize(root))));
}

