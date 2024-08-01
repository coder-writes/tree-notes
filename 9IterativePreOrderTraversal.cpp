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
vector<int> iterativePreOrderTraversalUsingStack(TreeNode* root){
    vector<int>ans;
    if(root==NULL) return ans;
    stack<TreeNode*> st;
    st.push(root);
    while(!st.empty()){
        TreeNode* node = st.top();
        st.pop();
        if(node->right) st.push(node->right);
        if(node->left) st.push(node->left);

        ans.push_back(node->data);
    }
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
    
    vector<int> res = iterativePreOrderTraversalUsingStack(root);

    for(auto val: res){
        cout<<val<<endl;
    }


}