/*
Given a Binary Tree, find the maximum width of it. Maximum width is defined as the maximum number of nodes in any level.
For example, maximum width of following tree is 4 as there are 4 nodes at 3rd level.

          1
       /     \
     2        3
   /    \    /    \
  4    5   6    7
    \
      8

Example 1:

Input:
       1
     /    \
    2      3
Output: 2
Example 2:

Input:
        10
      /     \
    20      30
   /    \
  40    60
Output: 2
Your Task:
You don't have to read any input. Just complete the function getMaxWidth() that takes node as parameter and returns the maximum width. The printing is done by the driver code.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= Number of Nodes<= 105
0 <= nodes values <= 105
*/

class Solution {
  public:
    // Function to get the maximum width of a binary tree.
    int getMaxWidth(Node* root) {

        queue<Node*> q;
        q.push(root);
        int max=INT_MIN;
        while(!q.empty()){
            int size=q.size();
            if(size>max){
                max=size;
            }
            for(int i=0;i<size;i++){
                Node* r=q.front();
                q.pop();
                if(r->left){
                    q.push(r->left);
                }
                if(r->right){
                    q.push(r->right);
                }
            }
        }
        return max;
    }
};
