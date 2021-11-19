/* 
Given a binary tree, connect the nodes that are at same level. You'll be given an addition nextRight pointer for the same.
Initially, all the nextRight pointers point to garbage values. Your function should set these pointers to point next right for each node.
       10                   10 ------> NULL
      / \                /      \
     3   5       =>     3 ------> 5 --------> NULL
    / \     \          /   \       \
   4   1      2       4 --> 1 -----> 2 -------> NULL

Example 1:

Input:
     3
   /  \
  1    2
Output:
3 1 2
1 3 2
Explanation: The connected tree is
        3 ------> NULL
     /    \
    1-----> 2 ------ NULL
Example 2:

Input:
      10
    /   \
   20   30
  /  \
 40  60
Output:
10 20 30 40 60
40 20 60 10 30
Explanation: The connected tree is
         10 ----------> NULL
       /     \
     20 ------> 30 -------> NULL
   /    \
 40 ----> 60 ----------> NULL
Your Task:
You don't have to take input. Complete the function connect() that takes root as parameter and connects the nodes at same level. The printing is done by the driver code. First line of the output will be level order traversal and second line will be inorder travsersal

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 ≤ Number of nodes ≤ 10^5
0 ≤ Data of a node ≤ 10^5

*/

// CPP program to connect nodes
// at same level using extended
// pre-order traversal
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class node {
public:
	int data;
	node* left;
	node* right;
	node* nextRight;

	/* Constructor that allocates a new node with the
	given data and NULL left and right pointers. */
	node(int data)
	{
		this->data = data;
		this->left = NULL;
		this->right = NULL;
		this->nextRight = NULL;
	}
};

void connectRecur(node* p);

// Sets the nextRight of
// root and calls connectRecur()
// for other nodes
void connect(node* p)
{
	// Set the nextRight for root
	p->nextRight = NULL;

	// Set the next right for rest of the nodes
	// (other than root)
	connectRecur(p);
}

/* Set next right of all descendents of p.
Assumption: p is a complete binary tree */
void connectRecur(node* p)
{
	// Base case
	if (!p)
		return;

	// Set the nextRight pointer for p's left child
	if (p->left)
		p->left->nextRight = p->right;

	// Set the nextRight pointer
	// for p's right child p->nextRight
	// will be NULL if p is the right
	// most child at its level
	if (p->right)
		p->right->nextRight = (p->nextRight) ? p->nextRight->left : NULL;

	// Set nextRight for other
	// nodes in pre order fashion
	connectRecur(p->left);
	connectRecur(p->right);
}

/* Driver code*/
int main()
{

	/* Constructed binary tree is
				
	*/
	node* root = new node(10);
	root->left = new node(20);
	root->right = new node(30);
	root->left->left = new node(40);
	root->right->right = new node(60);


	// Populates nextRight pointer in all nodes
	connect(root);

	
	return 0;
}
