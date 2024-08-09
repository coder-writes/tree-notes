                                
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>

using namespace std;

// Node structure for the binary tree
struct Node {
    int data;
    Node* left;
    Node* right;
    // Constructor to initialize
    // the node with a value
    Node(int val) : data(val),
        left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Function to return the
    // Right view of the binary tree
    vector<int> rightsideView(Node* root) {
        // Vector to store
        // the result
        vector<int> res;

        // Get the level order
        // traversal of the tree
        vector<vector<int>> levelTraversal = levelOrder(root);

        // Iterate through each level and
        // add the last element to the result
        for (auto level : levelTraversal) {
            res.push_back(level.back());
        }

        return res;
    }

    // Function to return the
    // Left view of the binary tree
    vector<int> leftsideView(Node* root) {
        // Vector to store the result
        vector<int> res;

        // Get the level order
        // traversal of the tree
        vector<vector<int>> levelTraversal = levelOrder(root);

        // Iterate through each level and
        // add the first element to the result
        for (auto level : levelTraversal) {
            res.push_back(level.front());
        }

        return res;
    }
    vector<int> leftSideView(Node* root){
        vector<int> arr;


        recursionLeft(root,0,arr);

        return arr;
    }
private:
    // Function that returns the
    // level order traversal of a Binary tree 
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;

        // Return an empty vector
        // if the tree is empty
        if (!root) {
            return ans;
        }

        // Use a queue to perform
        // level order traversal
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            vector<int> level;

            // Process each node
            // in the current level
            for (int i = 0; i < size; i++) {
                Node* top = q.front();
                level.push_back(top->data);
                q.pop();

                // Enqueue the left
                // child if it exists
                if (top->left != NULL) {
                    q.push(top->left);
                }

                // Enqueue the right
                // child if it exists
                if (top->right != NULL) {
                    q.push(top->right);
                }
            }

            // Add the current
            // level to the result
            ans.push_back(level);
        }

        return ans;
    }

    //Recursive Function to Traversse the Binary Tree
    // populate the Left Side View

    void recursionLeft(Node* root,int level,vector<int> &arr){
        if(root==NULL){
            return;
        }

        if(arr.size()==level){
            arr.push_back(root->data);
        }

        recursionLeft(root->left,level+1,arr);

        recursionLeft(root->right,level+1,arr);
    }

    void recursionRight(Node* root,int level,vector<int> &arr){
        if(root==NULL){
            return ;
        }

        if(arr.size()==level){
            arr.push_back(root->data);
        }

        recursionRight(root->right,level+1,arr);
        recursionRight(root->left,level+1,arr);
    }
};




int main() {
    // Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(10);
    root->left->left->right = new Node(5);
    root->left->left->right->right = new Node(6);
    root->right = new Node(3);
    root->right->right = new Node(10);
    root->right->left = new Node(9);

    Solution solution;

        // Get the Right View traversal
    vector<int> rightView = solution.rightsideView(root);

    // Print the result for Right View
    cout << "Right View Traversal: ";
    for(auto node: rightView){
        cout << node << " ";
    }
    cout << endl;

    // Get the Left View traversal
    vector<int> leftView = solution.leftsideView(root);

    // Print the result for Left View
    cout << "Left View Traversal: ";
    for(auto node: leftView){
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
                                
                            