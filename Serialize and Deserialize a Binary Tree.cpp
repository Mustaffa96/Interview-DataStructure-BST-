/*
Serialization is to store a tree in an array so that it can be later restored and Deserialization is reading tree back from the array. Now your task is to complete the function serialize which stores the tree into an array A[ ] and deSerialize which deserializes the array to the tree and returns it.
Note: The structure of the tree must be maintained. Multiple nodes can have the same data.

Example 1:

Input:
      1
    /   \
   2     3
Output: 2 1 3
Example 2:

Input:
         10
       /    \
      20    30
    /   \
   40  60
Output: 40 20 60 10 30
Your Task:
The task is to complete two function serialize which takes the root node of the tree as input and stores the tree into an array and deSerialize which deserializes the array to the original tree and returns the root of it.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= Number of nodes <= 1000
1 <= Data of a node <= 1000
*/

class Solution
{
    public:
    //Function to serialize a tree and return a list containing nodes of tree.
    vector<int> serialize(Node *root) 
   {
       //Your code here
       //using level order traversal.
       
       vector<int> v;
   Node * var=NULL;
   if(root==NULL)
   {
       return v;
   }
   
   queue<Node *> q;
   q.push(root);
   while(q.empty()==false)
   {
       Node * temp=q.front();
       q.pop();
       
       if(temp==var)
       {
           v.push_back(-1);
           continue;
       }
       
       v.push_back(temp->data);
       
       if(temp->left!=NULL)
       {
           q.push(temp->left);
       }
       else
       {
           q.push(var);
       }
       
       if(temp->right!=NULL)
       {
           q.push(temp->right);
       }
       else
       {
           q.push(var);
       }
       
   }
   
   return v;
      
   }
    
    //Function to deserialize a list and construct the tree.
    Node *deSerialize(vector<int> &A)
    {
      //Your code here
      if(A.size()==0)
      {
          return NULL;
      }
      Node * root;
      if(A[0]!=-1) root = new Node(A[0]);
      else 
      {
          root = NULL;
      }
      queue<Node*>q;
      q.push(root);
      int i=0;
      while(!q.empty())
      {
          Node* t = q.front();
          q.pop();
          if(A[i+1]!=-1)
          {
              t->left = new Node(A[i+1]);
              q.push(t->left);
          }
          else
          {
              t->left = NULL;
          }
       
          if(A[i+2]!=-1){
              t->right = new Node(A[i+2]);
              q.push(t->right);
          }
          else
          {
              t->right = NULL;
          }
       
          i+=2;
      }
   
      return root;
   
    }

};
