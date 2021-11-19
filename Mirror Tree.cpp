/* 
Given a Binary Tree, convert it into its mirror.
MirrorTree1            

Example 1:

Input:
      1
    /  \
   2    3
Output: 2 1 3
Explanation: The tree is
   1    (mirror)  1
 /  \    =>      /  \
3    2          2    3
The inorder of mirror is 2 1 3
Example 2:

Input:
      10
     /  \
    20   30
   /  \
  40  60
Output: 30 10 60 20 40
Explanation: The tree is
      10               10
    /    \  (mirror) /    \
   20    30    =>   30    20
  /  \                   /   \
 40  60                 60   40
The inroder traversal of mirror is
30 10 60 20 40.
Your Task:
Just complete the function mirror() that takes node as paramter  and convert it into its mirror. The printing is done by the driver code only.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
1 ≤ Number of nodes ≤ 105
1 ≤ Data of a node ≤ 105
*/

// C++ program to convert a binary tree
// to its mirror
#include<bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer
to left child and a pointer to right child */
struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
};

/* Helper function that allocates a new node with
the given data and NULL left and right pointers. */
struct Node* newNode(int data)
{
	struct Node* node = (struct Node*)
						malloc(sizeof(struct Node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	
	return(node);
}


/* Change a tree so that the roles of the left and
	right pointers are swapped at every node.

So the tree...
	4
	/ \
	2 5
	/ \
1 3

is changed to...
	4
	/ \
	5 2
		/ \
	3 1
*/
void mirror(struct Node* node) //code starts here
{
	if (node == NULL)
		return;
	else
	{
		struct Node* temp;
		
		/* do the subtrees */
		mirror(node->left);
		mirror(node->right);
	
		/* swap the pointers in this node */
		temp	 = node->left;
		node->left = node->right;
		node->right = temp;
	}
}

/* Helper function to print
Inorder traversal.*/
void inOrder(struct Node* node)
{
	if (node == NULL)
		return;
	
	inOrder(node->left);
	cout << node->data << " ";
	inOrder(node->right);
}


// Driver Code
int main()
{
	struct Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	
	/* Print inorder traversal of the input tree */
	cout << "Inorder traversal of the constructed"
		<< " tree is" << endl;
	inOrder(root);
	
	/* Convert tree to its mirror */
	mirror(root);
	
	/* Print inorder traversal of the mirror tree */
	cout << "\nInorder traversal of the mirror tree"
		<< " is \n";
	inOrder(root);
	
	return 0;
}


