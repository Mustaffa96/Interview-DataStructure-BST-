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

#include <bits/stdc++.h>
using namespace std;

class Node{
	public:             
	int data;           //value
	Node *left;    //pointer to left child
	Node *right;   //pointer to right child
};

// creating new node
Node* newnode(int data)  
{ 
	Node* node = (Node*)malloc(sizeof(Node)); 
	node->data = data; 
	node->left = NULL; 
	node->right = NULL; 
	return(node); 
}

Node* buildTree(Node* root,int key){
	if(!root)
		return NULL;
	if(root->data==key){
		return root->left; //only left subtree not deleted
	}
	else if(root->data>key)
		return buildTree(root->left,key); //recur for left subtree
	else{
		//root not deleted
		//left subtree not deleted
		//buld right subtree
		root->right=buildTree(root->right,key); 
		return root;
	}
}

Node* deleteNode(Node* root, int key)
{
	root=buildTree(root,key);
	return root; 
}

void levelwisedisplay(Node *root)
{
	//to display the tree level wise
	queue<Node*> q;

	Node* temp;
	int count=0;
	q.push(root);
	q.push(NULL);

	while(!q.empty()){
		temp=q.front();
		q.pop();

		if(temp==NULL){
			if(!q.empty())
				q.push(NULL);
			cout<<"\nend of level "<<count++<<endl;
		}
		else{
			cout<<temp->data<<" ";
			if(temp->left)
				q.push(temp->left);
			if(temp->right)
				q.push(temp->right);
		}
	}
	return ;
}

int main(){
	cout<<"tree is built as per example\n";

	Node *root=newnode(4); 
	root->left= newnode(1); 
	root->right= newnode(9); 


	printf("Displaying level wise\n");
	levelwisedisplay(root);

	root=deleteNode(root,2);//as per example

	printf("after deleting nodes greater or equal to 2\n");
	levelwisedisplay(root);

	return 0;
}
