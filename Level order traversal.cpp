/*
Given a binary tree, find its level order traversal.
Level order traversal of a tree is breadth-first traversal for the tree.


Example 1:

Input:
    1
  /   \ 
 3     2
Output:1 3 2
Example 2:

Input:
        10
     /      \
    20       30
  /   \
 40   60
Output:10 20 30 40 60

Your Task:
You don't have to take any input. Complete the function levelOrder() that takes the root node as input parameter and returns a list of integers containing the level order traversal of the given Binary Tree.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)


Constraints:
1 ≤ Number of nodes ≤ 105
1 ≤ Data of a node ≤ 105
*/

class Solution
{
    public:
    //Function to return the level order traversal of a tree.
    vector<int> levelOrder(Node* node)
        {
      //Your code here
      queue<Node*> q;
      vector<int> v;
      q.push(node);
      while(!q.empty()){
          int size=q.size();
          for(int i=0;i<size;i++){
              Node* node1=q.front();
              q.pop();
              v.push_back(node1->data);
              if(node1->left){
                  q.push(node1->left);
              }
              if(node1->right){
                  q.push(node1->right);
              }
          }
      }
      return v;
    }
};
