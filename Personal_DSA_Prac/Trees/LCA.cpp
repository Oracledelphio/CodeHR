#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val){
        this->val = val;
        left = nullptr;
        right = nullptr;
    }
};

TreeNode* LowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
    if (root == nullptr || root == p || root == q) return root;
    TreeNode* left = LowestCommonAncestor(root->left,p,q);
    TreeNode* right = LowestCommonAncestor(root->right, p, q);
    if (left != nullptr && right != nullptr){
        return root;
    }
    return (left!=nullptr) ? left: right;
}