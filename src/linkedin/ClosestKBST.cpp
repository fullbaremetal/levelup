#include "ClosestKBST.hpp"
#include <stack>
#include <cmath>


void inorder(TreeNode* root, bool rev, double target, stack<int> &s) {
    if(root==nullptr) return;
    inorder(rev?root->right:root->left, rev, target, s);
    if((!rev && root->val>target) || (rev && root->val<=target)) return;
    s.push(root->val);
    inorder(rev?root->left:root->right, rev, target, s);
}

vector<int> ClosestKBST::closestKValues(TreeNode* root, double target, int k){
    stack<int> s1,s2;
    inorder(root, false, target, s1);
    inorder(root, true, target, s2);
    vector<int> ans;
    while(!s1.empty() && !s2.empty()) {
        if(abs(s1.top()-target)>abs(s2.top()-target)) {
            ans.push_back(s2.top());
            s2.pop();
        } else {
            ans.push_back(s1.top());
            s1.pop();
        }
        if(ans.size()==k) return ans;
    }
    while(!s1.empty()) {
        ans.push_back(s1.top());
        s1.pop();
        if(ans.size()==k) return ans;
    }
    while(!s2.empty()) {
        ans.push_back(s2.top());
        s2.pop();
        if(ans.size()==k) return ans;
    }
    return ans;
}