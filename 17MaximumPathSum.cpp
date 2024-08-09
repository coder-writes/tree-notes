#include <bits/stdc++.h>
using namespace std;

//To find the diameter of a binary tree, we can think of every node as a potential `Curving Point` of the path along which we find the sum. The maximum sum of a path through a turning point (like a curve) can be found by adding the maximum sum achievable in the left subtree, the right subtree, and the value of the turning point.

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

int maxi = INT_MIN;

int findMaxPath(TreeNode* root,int maxi){
    if(root==NULL){
        return 0;
    }

    int leftMaxPath = max(0,findMaxPath(root->left,maxi));
    int rightMaxPath = max(0,findMaxPath(root->right,maxi));

    maxi = max(maxi,leftMaxPath+rightMaxPath + root->data);

    return max(leftMaxPath,rightMaxPath) + root->data;
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