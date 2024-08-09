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

void helper(TreeNode* root,vector<vector<int>> &result,vector<int>&arr){

    if(root==NULL){
        return;
    }
    // vector<int> arr;
    arr.push_back(root->data);
    if(root->left==NULL && root->right==NULL){
        result.push_back(arr);
    }
    helper(root->left,result,arr);
    helper(root->right,result,arr);
    arr.pop_back();

}


vector<vector<int>> rootToLeafAllPaths(TreeNode* root){
    vector<vector<int>> result;
    if(root==NULL){
        return result;
    }
    vector<int> arr;
    helper(root,result,arr);
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
    

    for(auto &val: rootToLeafAllPaths(root)){
        for(auto &res: val){
            cout<<res<<" ";
        }
        cout<<endl;
    }
}