#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data){
        val =data;
        left = nullptr;
        right = nullptr;
    }
};

// Whatever order you write the tree whether it be preorder, inorder etc. you deserialize using the same. It is converting a Tree to string and
// string back to tree. It is useful in signal transmission etc.

void serializeHelper(TreeNode* node, string& result){
    if (node == nullptr){
        result += "#,";
        return;
    }
    result += to_string(node->val) + ",";
    serializeHelper(node->left, result);
    serializeHelper(node->right, result);
}
string serialize(TreeNode* root){
    string result;
    serializeHelper(root,result);
    return result;
}

TreeNode* deserializeHelper(queue<string>& tokens) {
    string token = tokens.front();
    tokens.pop();

    if (token == "#") return nullptr;

    TreeNode* node = new TreeNode(stoi(token));
    node->left = deserializeHelper(tokens);
    node->right = deserializeHelper(tokens);
    return node;
}

TreeNode* deserialize(string data) {
    queue<string> tokens;
    stringstream ss(data);
    string token;
    while (getline(ss, token, ',')) {
        tokens.push(token);
    }
    return deserializeHelper(tokens);
}