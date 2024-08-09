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
vector<vector<int>> zigZagTraversal(TreeNode* root){
    vector<vector<int>> result;

    if(root==NULL){
        return result;
    }

    queue<TreeNode*>q;
    bool leftToRight = true;
    q.push(root);
    while(!q.empty()){
        int size = q.size(); 
        vector<int> temp(size);

        for(int i=0;i<size;i++){
            TreeNode* node = q.front();
            q.pop();
            

            //this is the only change in the level Order Traversal and zig Zag order Traversal

            int index = leftToRight ? i : (size-i-1);

            temp[index] = node->data;

            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);


        }
        leftToRight = !leftToRight;
        result.push_back(temp);
    }
    return result;
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


    cout<<zigZagTraversal(root).size()<<endl;
    for(auto &val: zigZagTraversal(root)){
        for(auto &ele : val){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
    


}