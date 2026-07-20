#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

// ---------- Insert ----------
TreeNode* insert(TreeNode* node, int val) {
    if (node == nullptr) return new TreeNode(val);

    if (val < node->val) {
        node->left = insert(node->left, val);
    } else if (val > node->val) {
        node->right = insert(node->right, val);
    }

    return node;
}

TreeNode* search(TreeNode* node, int target){
    if (node == nullptr || node->val == target) return node;
    if (target < node->val) return search(node->left, target);
    return search(node->right, target);
}

TreeNode* findMin (TreeNode* node){
    while (node->left != nullptr){
        node = node->left;
    }
    return node;
}

TreeNode* deleteNode(TreeNode* node, int target){
    if (node == nullptr) return nullptr;

    if (target < node->val){
        node->left = deleteNode(node->left, target);
    }
    else if (target> node->val){
        node->right = deleteNode(node->right, target);
    }else{
        if (node->left == nullptr){
            TreeNode* temp = node->right;
            delete node;
            return temp;
        }
        if (node->right == nullptr){
            TreeNode* tmp = node->left;
            delete node;
            return tmp;
        }
        
        TreeNode* successor = findMin(node->right);
        node->val = successor->val;
        node->right = deleteNode(node->right, successor->val);
    }
    return node;
}

void inorder(TreeNode* node) {
    if (node == nullptr) return;
    inorder(node->left);
    cout << node->val << " ";
    inorder(node->right);
}

// ---------- Cleanup ----------
void deleteTree(TreeNode* node) {
    if (node == nullptr) return;
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

bool isValidBSTHelper ( TreeNode* node, long long minVal, long long maxVal){
    if (node == nullptr) return true;
    if (node->val <= minVal || node->val >= maxVal) return false;

    return isValidBSTHelper(node->left, minVal, node->val) && isValidBSTHelper(node->right, node->val, maxVal);
}

bool isValidBST(TreeNode* root){
    return isValidBSTHelper(root, LLONG_MIN, LLONG_MAX);
}

TreeNode* buildBST ( vector<int>& nums, int left, int right){
    if (left > right) return nullptr;
    int mid = left + (right-left) /2;
    TreeNode* root = new TreeNode(nums[mid]);
    root->left = buildBST(nums, left, mid-1);
    root->right = buildBST(nums, mid+1, right);
    return root;
}

TreeNode* sortedArrToBST(vector<int>& nums){
    return buildBST(nums,0,nums.size()-1);
}

int main() {
    TreeNode* root = nullptr;

    // Build:        10
    //              /  \
    //             5    15
    //            / \   /  \
    //           3   7 12  20
    int values[] = {10, 5, 15, 3, 7, 12, 20};
    for (int v : values) {
        root = insert(root, v);
    }

    cout << "Inorder (should be sorted): ";
    inorder(root);
    cout << endl;

    // Search tests
    TreeNode* found = search(root, 7);
    cout << "Search 7: " << (found != nullptr ? "Found" : "Not Found") << endl;

    TreeNode* notFound = search(root, 100);
    cout << "Search 100: " << (notFound != nullptr ? "Found" : "Not Found") << endl;

    // Delete leaf (3)
    root = deleteNode(root, 3);
    cout << "After deleting 3: ";
    inorder(root);
    cout << endl;

    // Delete node with one child (after 3 is gone, 5 now has only right child 7)
    root = deleteNode(root, 5);
    cout << "After deleting 5: ";
    inorder(root);
    cout << endl;

    // Delete node with two children (10, the root)
    root = deleteNode(root, 10);
    cout << "After deleting 10 (root, two children): ";
    inorder(root);
    cout << endl;

    deleteTree(root);
    return 0;
}