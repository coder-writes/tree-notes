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
 TreeNode* buildTreeHelper(vector<int>&postOrder,int postStart,int postEnd,vector<int>&inOrder,int inStart,int inEnd,map<int,int> &mp){
    if(postStart>postEnd || inStart>inEnd){
        return NULL;
    }

    int rootVal = postOrder[postEnd];
    TreeNode* root = new TreeNode(rootVal);

    int rootStart = mp[rootVal];
    int leftSubTreeSize = rootStart - inStart;

    // root->left = buildTreeHelper(postOrder,postStart,)
    root->left = buildTreeHelper(postOrder, postStart, postStart + leftSubTreeSize - 1, inOrder, inStart, rootStart - 1, mp);
    root->right = buildTreeHelper(postOrder, postStart + leftSubTreeSize, postEnd - 1, inOrder, rootStart + 1, inEnd, mp);
 
    return root;
 }

TreeNode* buildTree(vector<int>&postOrder , vector<int>&inOrder){
    map<int,int> mp;

    for(int i=0;i<inOrder.size();i++){
        mp[inOrder[i]] = i;
    }

    TreeNode* root = buildTreeHelper(postOrder,0,postOrder.size()-1,inOrder,0,inOrder.size()-1,mp);
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
    


}