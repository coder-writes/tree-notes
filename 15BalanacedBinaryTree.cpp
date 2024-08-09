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
//A binary tree is balanced if the height of the tree is O(Log n) where n is the number of nodes. For Example, the AVL tree maintains O(Log n) height by making sure that the difference between the heights of the left and right subtrees is at most 1. Red-Black trees maintain O(Log n) height by making sure that the number of Black nodes on every root-to-leaf path is the same and that there are no adjacent red nodes. Balanced Binary Search trees are performance-wise good as they provide O(log n) time for search, insert and delete. 


//There are mainly Three Conoditions of the Balanced Binary Tree

// 1. The height of the Left and Right Tree for any Node does not differ by more than 1.
//2.The left Subtree of the Node is also Balanced.


//Time Complexity :- o(n)
//Space Complexity :- O(1)
int maxHeight(TreeNode* root){
    if(root==NULL) return 0;

    int lh = maxHeight(root->left);
    if(lh==-1) return -1;

    int rh = maxHeight(root->right);
    if(rh==-1) return -1;

    if(abs(lh-rh)>1) return -1;

    return 1 + max(lh,rh);
}
bool isBalanced1(TreeNode* root){
    return maxHeight(root)!=-1;
}
//Time Complexity :- O(n^2)

int getHeight(TreeNode* root){
    if(root==NULL)  return 0;

    int lh = getHeight(root->left);
    int rh = getHeight(root->right);

    return max(lh,rh) + 1;

}
bool isBalanced2(TreeNode* root){
    if(root==NULL);


    int leftHeight  = getHeight(root->left);
    int rightHeight = getHeight(root->right);

    if(abs(leftHeight-rightHeight)<=1 && isBalanced2(root->left) && isBalanced2(root->right)){
        return true;
    }
    return false;
    
}

//This is a Helper Function which is used to give the Height Of the Left or Right SubTree
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
    

    cout<<isBalanced1(root)<<endl;


}