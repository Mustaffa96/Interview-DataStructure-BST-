/*
Given an array of size N that can be used to represents a tree. The array indexes are values in tree nodes and array values give the parent node of that particular index (or node). The value of the root node index would always be -1 as there is no parent for root. Construct the standard linked representation of Binary Tree from this array representation.


Example 1:

Input:
N = 7
parent[] = {-1,0,0,1,1,3,5}
Output: 0 1 2 3 4 5 6
Explanation: the tree generated
will have a structure like 
          0
        /   \
       1     2
      / \
     3   4
    /
   5
 /
6
Example 2:

Input:
N = 3
parent[] = {2, 0, -1}
Output: 2 0 1
Explanation: the tree generated will
have a sturcture like
               2
             /   
            0      
          /   
         1     

Your Task:
You don't need to read input or print anything. The task is to complete the function createTree() which takes 2 arguments parent[] and N and returns the root node of the constructed tree.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)


Constraints:
1 ≤ N ≤ 103
*/

class Solution{
  public:
    //Function to construct binary tree from parent array.
    Node *createTree(int parent[], int N)
    {
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<N;i++)
            mp[parent[i]].push_back(i);
        queue<Node*>q;
        Node* root=new Node(mp[-1][0]);
        q.push(root);
        while(!q.empty())
        {
            Node* curr=q.front();
            q.pop();
            vector<int>v=mp[curr->data];
            Node* l=NULL,*r=NULL;
            for(int i=0;i<v.size();i++)
            {
                if(i==0){
                    l=new Node(v[i]);
                    curr->left=l;
                }
                if(i==1){
                    r=new Node(v[i]);
                    curr->right=r;
                }
            }
            if(curr->left)
                q.push(curr->left);
            if(curr->right)
                q.push(curr->right);
        }
        return root;
    }
};
