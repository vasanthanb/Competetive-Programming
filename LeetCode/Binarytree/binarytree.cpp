#include<bits/stdc++.h>

using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() {
        this->val = 0;
        this->left = NULL;
        this->right = NULL;
    }

    TreeNode(int val) {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }

    TreeNode(int val, TreeNode* left, TreeNode* right) {
        this->val = val;
        this->left = left;
        this->right = right;
    }
};

class BinaryTree {
public:
    TreeNode* root;

    BinaryTree() {
        this->root = NULL;
    }

    BinaryTree(int val) {
        this->root->val = val;
    }

    TreeNode* converttobinarytree(vector<int>& nums, int l, int r) {
        if (r < l)
            return NULL;
        int m = (l + r) / 2;
        return new TreeNode(nums[m], converttobinarytree(nums, l, m - 1), converttobinarytree(nums, m + 1, r));
    }

    void depthfirstsearch (TreeNode* root) {
        if(root == NULL) {
            return;
        }
        depthfirstsearch(root->left);
        cout << root->val << " ";
        depthfirstsearch(root->right);
    }
};

int main() {
    string input;
    getline(cin, input);
    stringstream stream(input);
    vector<int> values;
    int value;
    while(stream >> value) {
        values.push_back(value);
    }

    BinaryTree Tree;
    Tree.root = Tree.converttobinarytree(values, 0, values.size() - 1);
    Tree.depthfirstsearch(Tree.root);
}