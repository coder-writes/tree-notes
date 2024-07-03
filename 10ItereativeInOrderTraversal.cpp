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
vector<int> inOrderTraversal(TreeNode* root){
    stack<TreeNode*> st;
    TreeNode* node  = root;
    vector<int> inorder;
    while(true){
        if(node!=NULL){
            st.push(node);
            node = node->left;
        } 
        else{
            if(st.empty()==true) break;
            node = st.top();
            st.pop();
            inorder.push_back(node->data);
            node = node->right;
        }
    }
    return inorder;
}

//In this Part we will try to fo Itertive Traversal of the Tree without using recursion
int main(){

}