/*
Given a Binary Search Tree (with all values unique) and two node values. Find the Lowest Common Ancestors of the two nodes in the BST.

Example 1:

Input:
              5
           /    \
         4       6
        /         \
       3           7
                    \
                     8
n1 = 7, n2 = 8
Output: 7
Example 2:

Input:
     2
   /   \
  1     3
n1 = 1, n2 = 3
Output: 2
Your Task:
You don't need to read input or print anything. Your task is to complete the function LCA() which takes the root Node of the BST and two integer values n1 and n2 as inputs and returns the Lowest Common Ancestor of the Nodes with values n1 and n2 in the given BST. 

Expected Time Complexity: O(Height of the BST).
Expected Auxiliary Space: O(Height of the BST).

Constraints:
1 <= N <= 104
*/

// A recursive CPP program to find
// LCA of two nodes n1 and n2.
#include <bits/stdc++.h>
using namespace std;

class node
{
	public:
	int data;
	node* left, *right;
};

/* Function to find LCA of n1 and n2.
The function assumes that both
n1 and n2 are present in BST */
node *lca(node* root, int n1, int n2)
{
	if (root == NULL) return NULL;

	// If both n1 and n2 are smaller
	// than root, then LCA lies in left
	if (root->data > n1 && root->data > n2)
		return lca(root->left, n1, n2);

	// If both n1 and n2 are greater than
	// root, then LCA lies in right
	if (root->data < n1 && root->data < n2)
		return lca(root->right, n1, n2);

	return root;
}

/* Helper function that allocates
a new node with the given data.*/
node* newNode(int data)
{
	node* Node = new node();
	Node->data = data;
	Node->left = Node->right = NULL;
	return(Node);
}

/* Driver code*/
int main()
{
	// Let us construct the BST
	// shown in the above figure
	node *root = newNode(2);
	root->left = newNode(1);
	root->right = newNode(3);


	int n1 = 10, n2 = 14;
	node *t = lca(root, n1, n2);
	cout << "LCA of " << n1 << " and " << n2 << " is " << t->data<<endl;

	n1 = 14, n2 = 8;
	t = lca(root, n1, n2);
	cout<<"LCA of " << n1 << " and " << n2 << " is " << t->data << endl;

	n1 = 1, n2 = 3;
	t = lca(root, n1, n2);
	cout << "LCA of " << n1 << " and " << n2 << " is " << t->data << endl;
	return 0;
}


