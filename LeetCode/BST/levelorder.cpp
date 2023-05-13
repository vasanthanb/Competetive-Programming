#include <bits/stdc++.h>
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
    TreeNode(int x) {
        this->val = x;
        this->left = NULL;
        this->right = NULL;
    }
    TreeNode(int x, TreeNode* left, TreeNode* right) {
        this->val = x;
        this->left = left;
        this->right = right;
    }
};

/*
//recurssive aproach
vector<vector<int>> ans;

    void Traversal(TreeNode* node, int lev) {
        if (node == NULL) {
            return;
        }
        if (ans.size() >= lev + 1) {
            ans[lev].push_back(node->val);
        }
        else {
            ans.push_back({node->val});
        }
        Traversal(node->left, lev + 1);
        Traversal(node->right, lev + 1);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        Traversal(root, 0);
        return ans;
    }
*/

///*
//queue aproach
vector<int> levelOrder(TreeNode* root) {
    vector<int> ans; 
    if(root == NULL){ 
        return ans;
    } 
    queue<TreeNode*> q; 
    q.push(root);   
    while(!q.empty()) {
           
        TreeNode *temp = q.front(); 
        q.pop(); 
            
        if(temp->left != NULL) 
            q.push(temp->left); 
        if(temp->right != NULL) 
            q.push(temp->right); 
                
        ans.push_back(temp->val); 
    }
    return ans; 
}

//*/

int main() {
	TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    
    vector<int> ans = levelOrder(root);
    for(auto i : ans) {
        cout << i << " ";
    }
    cout << endl;
	return 0;
}