#include <bits/stdc++.h>
using namespace std;

//Level Order Traversal technique is defined as a method to traverse a Tree such that all nodes present in the same level are traversed completely before traversing the next level.
struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
//We need to visit the nodes in a lower level(0) before any node in a higher level, this idea is quite similar to that of a queue. Push the nodes of a lower level in the queue. When any level is visited, pop that nodes from the queue and push the child of that node in the queue.

// This ensures that the node of a lower level are visited prior to any node of a higher level.
vector<vector<int>> levelOrderTraversal(Node* root)
{
    vector<vector<int>> ans;
    if(root == NULL ) return ans;

    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        int size = q.size();
        vector<int> level;
        for(int i=0;i<size;i++)
        {
            Node* node = q.front();
            q.pop();
            if(node->left!=NULL) q.push(node->left);
            if(node->right!=NULL) q.push(node->right);
            level.push_back(node->data);
        }
    ans.push_back(level);
    }
    return ans;
}
int main()
{
    struct Node* root = new Node(2);
    root->left = new Node(5);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->left->left = new Node(3);
    root->left->left->right = new Node(2);
    root->right = new Node(7);
    root->right->left = new Node(9);
    root->right->left->left = new Node(2);
    root->right->left->right = new Node(3);
    root->right->right = new Node(1);
    root->right->left->right->left = new Node(1);
    root->right->left->right->right = new Node(4);


        for(auto &rows: levelOrderTraversal(root)){
            for(auto &val: rows){
                cout<<val<<" ";
            }
        }
}