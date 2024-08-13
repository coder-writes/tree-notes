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
//In the question you have given the preorder and inorder traversal vector
// you have to create a binary tree from the these two vectors , remember that wwe cannot create a unique binary tree from preorder Traversal and postOrder Traversal , we  can create only unique binary tree when inorder Traversal along with some other traversal is given.

// our inuttion is clear that we know that in preOrder Traversal First of all root is visited thereAfter left anf then Right(same applies for the left and right subtree) so first element of the preorder Traversal will always be the root of the tree.
// we will find the position of the this element in the inorder traversal because all the elements in the left of this element in the inorder Traversal will be our left SubTree and in the Right Will be our Rightr subTree (now we will applu the same logic on the left subtree and then in the right subtree recursively)

//time complexity is O(N);
//Space Complexity is O(N); due to map

    TreeNode* buildTreeHelper(vector<int> &preOrder, int preStart, int preEnd, vector<int> &inOrder, int inStart, int inEnd, map<int, int> &mp) {
        if (preStart > preEnd || inStart > inEnd) {
            return NULL;
        }

        int rootVal = preOrder[preStart];
        TreeNode* root = new TreeNode(rootVal);

        int rootIndex = mp[rootVal];
        int leftSubtreeSize = rootIndex - inStart;

        root->left = buildTreeHelper(preOrder, preStart + 1, preStart + leftSubtreeSize, inOrder, inStart, rootIndex - 1, mp);
        root->right = buildTreeHelper(preOrder, preStart + leftSubtreeSize + 1, preEnd, inOrder, rootIndex + 1, inEnd, mp);

        return root;
    }

TreeNode* buildTree(vector<int> &preOrder, vector<int>&inOrder){

    // we will store all the elements of the preOrder in order to access their index very quickly

    map<int,int> mp;
    for(int i=0;i<inOrder.size();i++){
        mp[inOrder[i]] = i;
    }

    TreeNode* root = buildTreeHelper(preOrder,0,preOrder.size()-1,inOrder,0,inOrder.size()-1,mp);
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
    


}