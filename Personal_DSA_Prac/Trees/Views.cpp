//Right and Left View are both DFS based, what the concept with this is that when we looked from the tree from the right or left side, which
//nodes are visible.

// For left view it is the first node processed at each level. In case of Right View it is the last node processed at each level.

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data){
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};


vector<int> rightSideView(TreeNode* root){
    vector<int> result;
    if (root == nullptr) return result;
    queue<TreeNode*> q;
    q.push(root); 

    while (q.empty()){
        int size = q.size();
        for (int i =0; i<size;i++){
            TreeNode* curr = q.front();
            q.pop();
            if (i == size-1) result.push_back(curr->data);

            if (curr->left !=nullptr) q.push(curr->left);
            if (curr->right != nullptr) q.push(curr->right);

        }

    }
    return result;
}

vector<int> leftSideView(TreeNode* root){
    vector<int> result;
    if (root == nullptr) return result;

    queue<TreeNode*> q;
    q.push(root);
    while (q.empty()){
        int size = q.size();
        for (int i =0; i<size; i++){
            TreeNode* curr = q.front();
            q.pop();

            if (i == 0) result.push_back(curr->data);
            if (curr->left != nullptr) q.push(curr->left);
            if (curr->right != nullptr) q.push(curr->right);
        }
    }
    return result;
}

