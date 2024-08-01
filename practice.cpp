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
vector<vector<int>> levelOrderTraversalUsingQueue(TreeNode* root){
    queue<TreeNode*> q;
    vector<vector<int>> result;
    if(root==NULL) return result;
    q.push(root);
    while(!q.empty()){
        vector<int> level;
        int size = q.size();

        for(int i=0;i<size;i++){
            TreeNode* node = q.front();
            q.pop();
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);

            level.push_back(node->data);

        }
        result.push_back(level);
    }
    return result;
}
vector<int> iterativeInOrderTraversalUsingStack(TreeNode* root){
    vector<int> ans;
    if(root==NULL) return ans;
    stack<TreeNode*> st;
    TreeNode* node = root;
    while(true){
        if(node!=NULL){
            st.push(node);
            node = node->left;
        }
        else{
            if(st.empty()) break;
            node = st.top();
            st.pop();
            ans.push_back(node->data);
            node = node->right;
        }
    }
    return ans;
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


    vector<vector<int>> res = levelOrderTraversalUsingQueue(root);

    for(auto &val: res){
        for(auto &it: val){
            cout<<it<<" ";
        }
        cout<<endl;
    }

    for(auto val: iterativeInOrderTraversalUsingStack(root)){
        cout<<val<<" ";
    }
}