/*
Given a Binary Search Tree. The task is to find the minimum element in this given BST.

Example 1:

Input:
           5
         /    \
        4      6
       /        \
      3          7
     /
    1
Output: 1
Example 2:

Input:
             9
              \
               10
                \
                 11
Output: 9
Your Task:
The task is to complete the function minValue() which takes root as the argument and returns the minimum element of BST. If the tree is empty, there is no minimum elemnt, so retutn -1 in that case.

Expected Time Complexity: O(Height of the BST)
Expected Auxiliary Space: O(Height of the BST).

Constraints:
1 <= N <= 104
*/




int minValue(struct Node *root) {
    if (root == NULL)
      return minValue;
 
    // Return minimum of 3 values:
    // 1) Root's data 2) Max in Left Subtree
    // 3) Max in right subtree
    int res = root->data;
    int lres = minValue(root->left);
    int rres = minValue(root->right);
    if (lres < res)
      res = lres;
    if (rres < res)
      res = rres;
    return res;
}


//Fullcode
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
 
// A tree node
class Node {
public:
    int data;
    Node *left, *right;
 
    /* Constructor that allocates a new
    node with the given data and NULL
    left and right pointers. */
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
int main()
{
    Node* NewRoot = NULL;
    Node* root = new Node(2);
    root->left = new Node(7);
    root->right = new Node(5);
    root->left->right = new Node(6);
    root->left->right->left = new Node(1);
    root->left->right->right = new Node(11);
    root->right->right = new Node(9);
    root->right->right->left = new Node(4);
 
    // Function call
    cout << "Minimum element is " << findMin(root) << endl;
 
    return 0;
}
int findMin(struct Node* root)
{
    // Base case
    if (root == NULL)
      return INT_MAX;
 
    // Return minimum of 3 values:
    // 1) Root's data 2) Max in Left Subtree
    // 3) Max in right subtree
    int res = root->data;
    int lres = findMin(root->left);
    int rres = findMin(root->right);
    if (lres < res)
      res = lres;
    if (rres < res)
      res = rres;
    return res;
}
