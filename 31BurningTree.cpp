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

/**
 * @brief Finds a node with a specific value in a binary tree.
 * 
 * This function recursively searches for a node with the given value in a binary tree starting from the root node.
 * If the root node is nullptr or the value is found at the root node, the function returns the root node.
 * Otherwise, it recursively searches for the value in the left and right subtrees of the root node.
 * If the value is found in the left subtree, the function returns the node with the value.
 * If the value is not found in the left subtree, the function continues searching in the right subtree.
 * If the value is found in the right subtree, the function returns the node with the value.
 * If the value is not found in the right subtree, the function returns nullptr.
 * 
 * @param root A pointer to the root node of the binary tree.
 * @param val The value to search for in the binary tree.
 * @return TreeNode* A pointer to the node with the given value if found, nullptr otherwise.
 */
TreeNode* findNode(TreeNode* root,int val){
    if(root==nullptr) return nullptr;
    if(root->data == val) return root;
    
    TreeNode* left = findNode(root->left,val);
    if(left) return left;
    return findNode(root->right,val);
}
void markMyParents(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &parents_data){
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode* node = q.front();
        q.pop();
        if(node->left){
            q.push(node->left);
            parents_data[node->left] = node;
        }
        if(node->right){
            q.push(node->right);
            parents_data[node->right] = node;
        }
    }
}
int minTime(TreeNode* root,int target){
    unordered_map<TreeNode* ,TreeNode*> parents_data;
    markMyParents(root,parents_data);

    unordered_map<int,bool> burnt_node;
    burnt_node[target] = true;
    int time = 0;
    queue<TreeNode*> q;
    TreeNode* nodal = findNode(root,target);
    q.push(nodal);
    while(!q.empty()){
        int size = q.size();
        // time+=1;
        bool burnt = false;
        for(int i=0;i<size;i++){
            TreeNode* node = q.front();
            q.pop();
            if(node->left && !burnt_node[node->left->data]){
                q.push(node->left);
                burnt_node[node->left->data] =  1;
                burnt = true;
            }
            if(node->right && !burnt_node[node->right->data]){
                q.push(node->right);
                burnt_node[node->right->data] = 1;
                burnt = true;
            }
            if(parents_data[node] && !burnt_node[parents_data[node]->data]){
                q.push(parents_data[node]);
                burnt_node[parents_data[node]->data] = 1;
                burnt = true;
            }
        }
        if(burnt) time+=1;
    }
    return time;
}
int main(){
    struct TreeNode*  root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right->right = new TreeNode(6);
    root->right->right->right = new TreeNode(9);
    root->right->right->right->right = new TreeNode(10);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(8);

    cout<<minTime(root,8);

   
    
}