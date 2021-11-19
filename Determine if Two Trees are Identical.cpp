/*
Given two binary trees, the task is to find if both of them are identical or not. 


Example 2:

Input:
     1          1
   /   \      /   \
  2     3    2     3
Output: Yes
Explanation: There are two trees both
having 3 nodes and 2 edges, both trees
are identical having the root as 1,
left child of 1 is 2 and right child
of 1 is 3.
Example 2:

Input:
    1       1
  /  \     /  \
 2    3   3    2
Output: No
Explanation: There are two trees both
having 3 nodes and 2 edges, but both
trees are not identical.

Your task:
Since this is a functional problem you don't have to worry about input, you just have to complete the function isIdentical() that takes two roots as parameters and returns true or false. The printing is done by the driver code.


Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree).


Constraints:
1 <= Number of nodes <= 10^5
1 <=Data of a node <= 10^5
*/

class Solution
{
    public:
    //Function to check if two trees are identical.
    bool isIdentical(Node *r1, Node *r2)
    {
            // Return true if both trees are empty
    if (r1==NULL  && r2==NULL) return true;
 
    // Return false if one is empty and other is not
    if (r1 == NULL) return false;
    if (r2 == NULL) return false;
     
    // Create an empty queues for simultaneous traversals
    queue<Node *> q1, q2;
 
    // Enqueue Roots of trees in respective queues
    q1.push(r1);
    q2.push(r2);
 
    while (!q1.empty() && !q2.empty())
    {
        // Get front nodes and compare them
        Node *n1 = q1.front();
        Node *n2 = q2.front();
 
        if (n1->data != n2->data)
           return false;
 
        // Remove front nodes from queues
        q1.pop(), q2.pop();
 
        /* Enqueue left children of both nodes */
        if (n1->left && n2->left)
        {
            q1.push(n1->left);
            q2.push(n2->left);
        }
 
        // If one left child is empty and other is not
        else if (n1->left || n2->left)
            return false;
 
        // Right child code (Similar to left child code)
        if (n1->right && n2->right)
        {
            q1.push(n1->right);
            q2.push(n2->right);
        }
        else if (n1->right || n2->right)
            return false;
    }
 
    return true;
    }
};
