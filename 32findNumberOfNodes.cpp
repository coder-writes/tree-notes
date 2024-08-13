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
int counter(TreeNode* root,int &cnt){
    if(root==nullptr) return 0;

    cnt++;
    if(root->left) counter(root->left,cnt);
    if(root->right) counter(root->right,cnt);
    
    return cnt;
}

//this function is to count the number of nides in a binary tree
int countNodes(TreeNode* root){
   int cnt = 0; 
    return counter(root,cnt);
    //time complexity of this is O(n);
}

//Note:- when we are given a complete binary tree then we can even calculate the number of nodes in lesser time o((logn)^2)
//A complete binary tree is a binary tree in which all levels, except possibly the last, are completely filled, and all nodes are as left as possible. In other words, a complete binary tree is a binary tree in which all nodes are present in the leftmost positions of each level, except for the last level, which is filled from left to right.x


int countNode(TreeNode* root){
    if(root==NULL) return 0;

    int lh = findLeft(root->left);
    int rh= findRight(root->right);

    if(lh==rh) return(1<<lh)-1;
    return 1 + countNode(root->left) + countNode(root->right);
}
int findLeft(TreeNode* root){
    int hght = 0;
    while(root){
        hght++;
        root=root->left;
    }
    return hght;

}
int findRight(TreeNode* root){
    int hght = 0;
    while(root){
        hght++;
        root= root->right;
    }
    return hght;
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

    cout<<countNodes(root)<<endl;
    


}