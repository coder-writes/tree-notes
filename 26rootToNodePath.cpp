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
bool helper(TreeNode* root,int A,vector<int> &arr){
    if(root==NULL){
        return false;
    }

    arr.push_back(root->data);
    if(root->data==A){
        return true;
    }

    if(helper(root->left,A,arr) || helper(root->right,A,arr))
        return true;

    arr.pop_back();
    return false;
}
vector<int>  rootToNodePath(TreeNode* root,int A){
    vector<int>arr;
    if(root==NULL){
        return arr;
    }
    helper(root,A,arr);
    return arr;
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

    for(auto &val: rootToNodePath(root,1)){
        cout<<val<<" ";

    }



    


}