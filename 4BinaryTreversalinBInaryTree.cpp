// Unlike linear data structures (Array, Linked List, Queues, Stacks, etc) which have only one logical way to traverse them, trees can be traversed in different ways.

// Generally, there are 2 widely used ways for traversing trees:

// DFS or Depth-First Search
// // BFS or Breadth-First Search

// DFS (Depth-first search) is a technique used for traversing trees or graphs. Here backtracking is used for traversal. In this traversal first, the deepest node is visited and then backtracks to its parent node if no sibling of that node exists


// 1. Inorder Traversal
// Traverse the left subtree, i.e., call Inorder(left-subtree)
// Visit the root
// Traverse the right subtree, i.e., call Inorder(right-subtree)
// Time Complexity: O(N)
// Auxiliary Space: O(log N)

// Uses of Inorder traversal:
// In the case of binary search trees (BST), Inorder traversal gives nodes in non-decreasing order. To get nodes of BST in non-increasing order, a variation of Inorder traversal where Inorder traversal is reversed can be used.

// 2. Preorder Traversal
// Visit the root
// Traverse the left subtree, i.e., call Preorder(left-subtree)
// Traverse the right subtree, i.e., call Preorder(right-subtree)

// Time Complexity: O(N)
// Auxiliary Space: O(log N)

// Uses of Preorder:
// Preorder traversal is used to create a copy of the tree. Preorder traversal is also used to get prefix expressions of an expression tree.


// 3. Postorder Traversal (Practice):
// Follow the below steps to solve the problem:

// Traverse the left subtree, i.e., call Postorder(left-subtree)
// Traverse the right subtree, i.e., call Postorder(right-subtree)
// Visit the root


// Time Complexity: O(N)
// Auxiliary Space: O(log N)

// Uses of Postorder:
// Postorder traversal is used to delete the tree. Please see the question for the deletion of the tree for details. Postorder traversal is also useful to get the postfix expression of an expression tree