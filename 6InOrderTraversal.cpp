#include <bits/stdc++.h>

using namespace std;

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
void printInOrderTraversal(Node* root)
{
    if(root == NULL)
    {
        return;
    }

    printInOrderTraversal(root->left);
    cout<<root->data<<" ";
    printInOrderTraversal(root->right);
}
int main()
{
     struct Node* root = new Node(2);
    root->left = new Node(5);
    root->right = new Node(7);
    root->right->left = new Node(9);
    root->right->left->right = new Node(3);
    root->right->left->left = new Node(2);
    root->right->right = new Node(1);
    root->right->left->right->left = new Node(1);
    root->right->left->right->right = new Node(4);

    printInOrderTraversal(root);
}