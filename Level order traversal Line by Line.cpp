/*
Given a Binary Tree, your task is to find its level order traversal.
For the below tree the output will be 1 $ 2 3 $ 4 5 6 7 $ 8 $.

          1
       /     \
     2        3
   /    \     /   \
  4     5   6    7
    \
     8

Example 1:

Input:
          1
        /
       4
     /   \
    4     2
Output:1 $ 4 $ 4 2 $

Example 2:

Input:
            10
          /    \
        20      30
     /     \
    40     60
Output: 10 $ 20 30 $ 40 60 $
Your Task:
This is a function problem. You don't need to read input. Just complete the function levelOrder() that takes nodes as parameter and returns level order traversal as a 2D list.

Note: The driver code prints the levels '$' separated.
Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= Number of edges <= 1000
0 <= Data of a node <= 100
*/

vector<vector<int>> levelOrder(Node* node)
{
 vector<vector<int>> vec;
  queue<Node*> q;
  q.push(node);
  while(!q.empty()){
      int size=q.size();
      vector<int> vv;
      for(int i=0;i<size;i++){
          Node* root=q.front();
          q.pop();
          vv.push_back(root->data);
          if(root->left){
              q.push(root->left);
          }
          if(root->right){
              q.push(root->right);
          }
      }
        vec.push_back(vv);
  }
    return vec;
}
