#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;

    TreeNode(int val)
    {
        data = val;
        left = NULL;
        right =   NULL;
    }
    
};
vector<int> iterativeInOrderTraversalUsingTwoStack(TreeNode* root){
    
    vector<int> result;
    if(root== NULL) return result;

    stack<TreeNode*> st1,st2;

    st1.push(root);

    while(!st1.empty()){
        root = st1.top();

        st1.pop();

        st2.push(root);

        if(root->left) st1.push(root->left);
        if(root->right) st1.push(root->right);
    }

    while(!st2.empty()){
        result.push_back(st2.top()->data);
        st2.pop();
    }

    return result;
}

int main(){
    struct TreeNode*  root = new TreeNode(2);
    root->left = new TreeNode(5);
    root->left->left = new TreeNode(4);
    root->left->left->left  = new TreeNode(3);
    root->left->left->right  = new TreeNode(2);
    root->left->right = new TreeNode(5);
    root->right = new TreeNode(7);
    root->right->left = new TreeNode(9);
    root->right->left->right = new TreeNode(2);
    root->right->left->right->right = new TreeNode(4);
    root->right->left->right->left = new TreeNode(1);
    root->right->left->left = new TreeNode(3);
    root->right->right = new TreeNode(7);
    


    for(auto &val: iterativeInOrderTraversalUsingTwoStack(root)){
        cout<<val<<" ";

    }
}