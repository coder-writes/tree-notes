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
void inOrderTraversal(TreeNode* root){
    if(root==NULL){
        return ;
    }

    cout<<root->data<<" ";
    inOrderTraversal(root->left);
    inOrderTraversal(root->right);
}

TreeNode* helper(vector<int> &arr,int left,int right)
{
    if(left>right) return nullptr;

    int mid = left + (right - left)/2;

    TreeNode* root = new TreeNode(arr[mid]);
    root->left = helper(arr,left,mid-1);
    root->right = helper(arr,mid+1,right);

    return root;

}

TreeNode* convertArr2BST(vector<int> &nums){
    int n = nums.size();
    if(n==0){
        return nullptr;
    }

    TreeNode* root = helper(nums,0,n-1);
    return root;
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
    
    vector<int> arr = {1,2,4,5,7,3,2,9};
    TreeNode* root1 = convertArr2BST(arr);
    inOrderTraversal(root1);

}