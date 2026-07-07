#include <bits/stdc++.h>
#include <queue>
#include <vector>
using namespace std;


struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data){
        val = data;
        left = nullptr;
        right = nullptr;
    }
};

void preorder(TreeNode* node, vector<int>& result){
    if (node == nullptr) return;
    result.push_back(node->val);
    preorder(node->left, result);
    preorder(node->right, result);
}

void inorder(TreeNode* node, vector<int>& result){
    if (node == nullptr) return;
    inorder(node->left, result);
    result.push_back(node->val);
    inorder(node->right, result);
}

void postorder(TreeNode* node, vector<int>& result){
    if (node == nullptr) return;
    postorder(node->left, result);
    postorder(node->right, result);
    result.push_back(node->val);
}

// Implementing BFS (Level Order Traversal)
vector<vector<int>> levelOrder(TreeNode* root){
    vector<vector<int>> result;
    if (root == nullptr) return result;

    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()){
        int size = q.size();
        vector<int> level;

        for (int i = 0; i < size; i++){
            TreeNode* curr = q.front();
            q.pop();
            level.push_back(curr->val);
            if (curr->left != nullptr) q.push(curr->left);
            if (curr->right != nullptr) q.push(curr->right);
        }
        result.push_back(level);
    }
    return result;

}

void deleteTree(TreeNode* node){
    if (node == nullptr) return;
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

// ---------- Helper to print a vector ----------
void printVector(const vector<int>& v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); i++) {
        cout << v[i];
        if (i != v.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

int height (TreeNode* node){
    if (node == nullptr) return -1;
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    return 1 + max(leftHeight,rightHeight);
}

int diameterHelper (TreeNode* node, int& diameter){
    if (node == nullptr) return -1;

    int leftDiameter = diameterHelper(node->left, diameter);
    int rightDiameter = diameterHelper(node->right, diameter);

    diameter = max(diameter, 2+ leftDiameter + rightDiameter);

    return 1 + max(leftDiameter,rightDiameter);
}

int diameterOfBinaryTree(TreeNode* root){
    int diameter = 0;
    diameterHelper(root,diameter);
    return diameter;
}

int isBalancedTree(TreeNode* node, bool& isBalanced){
    if (node == nullptr) return -1;
    if (!isBalanced) return -1;

    int leftHeight = isBalancedTree(node->left,isBalanced);
    int rightHeight = isBalancedTree(node->right, isBalanced);

    if (abs(leftHeight-rightHeight) > 1){
        isBalanced = false;
    }

    return 1 + max(leftHeight, rightHeight);
}