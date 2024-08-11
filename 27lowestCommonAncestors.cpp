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
// Question In this part we have to find the lowest ancestor of both lowest ancestors means that the node whch connects both

// Initution Our Intitution to solve the Question is to store the root to node path of both the nodes in a vector and then compare the paths of both the nodes the last node where they become unequal is the the answer
bool helper(TreeNode* root,TreeNode* node,vector<TreeNode*> & arr){
    if(root==NULL){
        return false;
    }

    arr.push_back(root);

    if(root==node) return true;

    if((helper(root->left,node,arr))||(helper(root->right,node,arr)))
        return true;

    arr.pop_back();
}
TreeNode* LCAof2Nodes(TreeNode* root,TreeNode* A,TreeNode* B){
    vector<TreeNode*> firstTrack;
    vector<TreeNode*> secondTrack;

    helper(root,A,firstTrack);
    helper(root,B,secondTrack);

    int m  = firstTrack.size();
    int n = secondTrack.size();

    TreeNode* ans = firstTrack[0];
    
    for(int i=1;i<min(m,n);i++){
        if(firstTrack[i]==secondTrack[i]){
            ans = firstTrack[i];
        }
        else {
            return ans;
        }
    }
    return ans;

}

// the previous approach is using a extra space which can be reduced by optimizing the solution the problem approach
//we will do the DFS in the tree and each node in the tree will return the NULL untill we get the given node for exampled if any node has the same value as one the two given nodes then it will return only its node the TreeNode which gets both the node will be our answer

TreeNode* LCAof2Nodes2(TreeNode* root,TreeNode* A,TreeNode* B){
    if(root == NULL || root==A || root==B ){
        return root;
    }

    TreeNode* left = LCAof2Nodes2(root->left,A,B);
    TreeNode* right = LCAof2Nodes2(root->right,A,B);

    if(left==NULL){
        return left;
    }
    else if(right==NULL){
        return right;
    }
    else return root;
}
int main(){
    struct TreeNode*  root = new TreeNode(2);
    root->left = new TreeNode(5);
    root->left->left = new TreeNode(4);
    root->left->left->left  = new TreeNode(3);
    root->left->left->right  = new TreeNode(2);
    root->left->right = new TreeNode(5);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(9);
    root->right->left->right = new TreeNode(2);
    root->right->left->right->right = new TreeNode(4);
    root->right->left->right->left = new TreeNode(1);
    root->right->left->left = new TreeNode(3);
    root->right->right = new TreeNode(7);


    cout<<LCAof2Nodes(root,root->left->left->right, root->right->right)->data<<endl;
    


}