/*
Given a BST and a value k, the task is to delete the nodes having values greater than or equal to x.

Example 1:

Input:
    4   
   / \  
  1   9 
k = 2 
Output:
1
Your Task:
The task is to complete the function deleteNode() which takes root, k as the argument, and returns the root of tree after deleting values greater than or equal to x. The driver code will print the inorder traversal of the updated tree in output itself.

Expected Time Complexity: O(Size of tree)
Expected Auxiliary Space: O(1).

Constraints:
1 <= T <= 100
1 <= N <= 10^3
1 <= A[] <= 10^3
1 <= x <= N
*/

class Solution{
  public:
  
  Node* buildTree(Node* root,int k){
	if(!root)
		return NULL;
	if(root->data==k){
		return root->left; //only left subtree not deleted
	}
	else if(root->data>k)
		return buildTree(root->left,k); //recur for left subtree
	else{
		//root not deleted
		//left subtree not deleted
		//buld right subtree
		root->right=buildTree(root->right,k); 
		return root;
	}
}
  
    /*The function should return the root of the modified tree*/
    Node* deleteNode(Node* root, int k)
    {
	root=buildTree(root,k);
	return root; 
    }
};
