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

vector<int> bottomTraversal(TreeNode* root){
    map<int,int> mp;
    queue<pair<TreeNode*,int>> q;
    vector<int> arr;
    q.push({root,0});
    while(!q.empty()){
        auto p = q.front();
        q.pop();
        TreeNode* node = p.first;
        int level = p.second;

        mp[level] = node->data;

        if(node->left){
            q.push({node->left,level-1});
        }
        if(node->right){
            q.push({node->right,level+1});
        }
    }
    for(auto &val: mp){
        arr.push_back(val.second);
    }
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
    
    for(auto &val: bottomTraversal(root)){
        cout<<val<<" ";
    }


}