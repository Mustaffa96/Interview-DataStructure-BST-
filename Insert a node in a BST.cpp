/* Given a BST and a key K. If K is not present in the BST, Insert a new Node with a value equal to K into the BST. 
Note: If K is already present in the BST, don't modify the BST.


Example 1:

Input:
     2
   /   \
  1     3
K = 4
Output: 1 2 3 4
Explanation: After inserting the node 4
Inorder traversal will be 1 2 3 4.
Example 2:

Input:
        2
      /   \
     1     3
             \
              6
K = 4
Output: 1 2 3 4 6
Explanation: After inserting the node 4
Inorder traversal of the above tree
will be 1 2 3 4 6.

Your Task:
You don't need to read input or print anything. Your task is to complete the function insert() which takes the root of the BST and Key K as input parameters and returns the root of the modified BST after inserting K. 
Note: The generated output contains the inorder traversal of the modified tree.


Expected Time Complexity: O(Height of the BST).
Expected Auxiliary Space: O(Height of the BST).


Constraints:
1 <= Number of nodes <= 105
1 <= K <= 106 */

// C++ program to demonstrate insert operation
// in binary search tree
#include <bits/stdc++.h>
using namespace std;

// BST node
struct Node {
	int key;
	struct Node *left, *right;
};

// Utility function to create a new node
Node* newNode(int data)
{
	Node* temp = new Node;

	temp->key = data;

	temp->left = NULL;
	temp->right = NULL;

	return temp;
}

// A utility function to insert a new
// Node with given key in BST
Node* insert(Node* root, int key)
{
	// Create a new Node containing
	// the new element
	Node* newnode = newNode(key);

	// Pointer to start traversing from root and
	// traverses downward path to search
	// where the new node to be inserted
	Node* x = root;

	// Pointer y maintains the trailing
	// pointer of x
	Node* y = NULL;

	while (x != NULL) {
		y = x;
		if (key < x->key)
			x = x->left;
		else
			x = x->right;
	}

	// If the root is NULL i.e the tree is empty
	// The new node is the root node
	if (y == NULL)
		y = newnode;

	// If the new key is less then the leaf node key
	// Assign the new node to be its left child
	else if (key < y->key)
		y->left = newnode;

	// else assign the new node its right child
	else
		y->right = newnode;

	// Returns the pointer where the
	// new node is inserted
	return y;
}

// A utility function to do inorder
// traversal of BST
void Inorder(Node* root)
{
	if (root == NULL)
		return;
	else {
		Inorder(root->left);
		cout << root->key << " ";
		Inorder(root->right);
	}
}

// Driver code
int main()
{
	/* Let us create following BST
			2
		/   \
		1	  3
		     \
          4 */

	Node* root = NULL;
	root = insert(root, 2);
	insert(root, 2);
	insert(root, 1);
	insert(root, 3);
	insert(root, 4);


	// Print inorder traversal of the BST
	Inorder(root);

	return 0;
}
