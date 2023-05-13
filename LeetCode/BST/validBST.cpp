#include <bits/stdc++.h>

using namespace std;

struct node {
  int data;
  struct node * left, * right;
};

/*vector<int> inorderTraversal(node* root) {
    vector<int> ans;
        if(root == NULL) {
            return ans;
        }
        stack<node*> stack;
        while(true) {
            if(root != NULL) {
                stack.push(root);
                root = root->left;
            }
            else {
                if(stack.empty()) {
                    break;
                }
                root = stack.top();
                ans.push_back(root->data);
                stack.pop();
                root = root->right;
            }
        }
        return ans; 
    }*/

struct node * newNode(int data) {
  struct node * node = (struct node * ) malloc(sizeof(struct node));
  node -> data = data;
  node -> left = NULL;
  node -> right = NULL;

  return (node);
}

bool ans;
void check(node* root) {
    if(root->left != NULL) {
            check(root->left);
        }
    if(root->right != NULL) {
            check(root->right);
        } 
    if(root->left != NULL && root->right != NULL){
    if((root->left->data < root->data) && (root->right->data > root->data)) {
            ans = true;
        }
    else {
            ans = false;
        }
    }
}
    bool isValidBST(node* root) {
        if(root == NULL) {
            return false;
        }
        check(root);
        return ans;
    }

int main() {

  struct node * root = newNode(2);
  root -> left = newNode(1);
  root -> right = newNode(3);
  /*root -> left -> left = newNode(4);
  root -> left -> right = newNode(5);
  root -> right -> left = newNode(6);
  root -> right -> right = newNode(7);

  /*vector < int > inOrder;
  inOrder = inorderTraversal(root);

  cout << "The inOrder Traversal is : ";
  for (int i = 0; i < inOrder.size(); i++) {
    cout << inOrder[i] << " ";
  }*/
  return isValidBST(root);
}