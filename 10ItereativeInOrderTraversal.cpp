#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val){
        data = val;
        left = right = NULL;
    }

};
vector<int> ItertativeInOrderTraversalUsingStack(TreeNode* root){
    stack<TreeNode*> st;
    TreeNode* TreeNode  = root;
    vector<int> inorder;
    while(true){
        if(TreeNode!=NULL){
            st.push(TreeNode);
            TreeNode = TreeNode->left;
        } 
        else{
            if(st.empty()==true) break;
            TreeNode = st.top();
            st.pop();
            inorder.push_back(TreeNode->data);
            TreeNode = TreeNode->right;
        }
    }
    return inorder;
}

//In this Part we will try to fo Itertive Traversal of the Tree without using recursion
int main(){
    struct TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(5);
    root->right = new TreeNode(7);
    root->right->left = new TreeNode(9);
    root->right->left->left = new TreeNode(2);
    root->right->left->right = new TreeNode(3);
    root->right->right = new TreeNode(1);
    root->right->left->right->left = new TreeNode(1);
    root->right->left->right->right = new TreeNode(4);

    for(auto &val: ItertativeInOrderTraversalUsingStack(root)){
        cout<<val<<" ";
    }
}