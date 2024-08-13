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

//our Problem statement to prrint all nodes at distance k from a given node in a binary tree

//Approach: to print all the nodes at a distance from a given we should have acces to our parent node as well like we can acess our child node left child and right child for achieving this we will create a map data structure which will store the parent node of each node in the tree and then we will perform a bfs traversal to print all the nodes at a distance k from the given node 

//Time complexity: O(n) where n is the number of nodes in the tree
//Space complexity: O(n) where n is the number of nodes in the tree
void markMyParents(TreeNode* root,unordered_map<TreeNode*,TreeNode* > &parent_data){
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode* node = q.front();
        q.pop();
        if(node->left){
            parent_data[node->left] = node;
            q.push(node->left);
        }
        if(node->right){
            parent_data[node->right] = node;
            q.push(node->right);
        }
    }
}
vector<int> nodesAtDistancek(TreeNode* root,TreeNode* target,int k){
    unordered_map<TreeNode*,TreeNode*> parent_data;
    //this is the function which is used to mark the parents of very node in the tree using DFS traveral in the tree
    markMyParents(root,parent_data);

    // now we will find all the  nodes at a distance using bfs Traversal

    //wee will create a map data structure to mark nodes as visited
    unordered_map<TreeNode*,bool> visited_Node;
    queue<TreeNode*> q;
    vector<int> ans;
    q.push(target);
    visited_Node[target] = 1;
    int curr_level = 0;
    while(!q.empty()){
        int size = q.size();
        if(curr_level++ ==k) break;
        for(int i=0;i<size;i++){
            TreeNode* node = q.front();
            q.pop();
            if(node->left && !visited_Node[node->left]){
                q.push(node->left);
                visited_Node[node->left] = 1;
            }
            if(node->left && !visited_Node[node->right]){
                q.push(node->right);
                visited_Node[node->right] = 1;
            }
            if(parent_data[node] && !visited_Node[parent_data[node]]){
                q.push(parent_data[node]);
                visited_Node[parent_data[node]]  = 1;
            }

        }

    }
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            ans.push_back(node->data);
        }
        return ans;


}

int main(){
    struct TreeNode*  root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);  

    for(auto &val : nodesAtDistancek(root,root->left,2)){
        cout<<val<<" ";
    }

}