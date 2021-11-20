/*
Given a Binary Tree and a positive integer k. The task is to count all distinct nodes that are distance k from a leaf node. A node is at k distance from a leaf if it is present k levels above the leaf and also, is a direct ancestor of this leaf node. If k is more than the height of Binary Tree, then nothing should be counted.

Example 1:

Input:
        1
      /   \
     2     3
   /  \   /  \
  4   5  6    7
          \ 
          8
K = 2
Output: 2
Explanation: There are only two unique
nodes that are at a distance of 2 units
from the leaf node. (node 3 for leaf
with value 8 and node 1 for leaves with
values 4, 5 and 7)
Note that node 2
isn't considered for leaf with value
8 because it isn't a direct ancestor
of node 8.
Example 2:

Input:
          1
         /
        3
       /
      5
    /  \
   7    8
         \
          9
K = 4
Output: 1
Explanation: Only one node is there
which is at a distance of 4 units
from the leaf node.(node 1 for leaf
with value 9) 
Your Task:
You don't have to read input or print anything. Complete the function printKDistantfromLeaf() that takes root node and k as inputs and returns the number of nodes that are at distance k from a leaf node. Any such node should be counted only once. For example, if a node is at a distance k from 2 or more leaf nodes, then it would add only 1 to our count.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
1 <= N <= 105
*/

unordered_map<Node*,int> mp;
vector<string> ret;
void helper(Node *root,string s){
    if(!root)
        return;
    if(!root->left and !root->right){
        ret.push_back(s);
    }
    helper(root->left,s + "l");
    helper(root->right,s + "r" );
}
//Function to return count of nodes at a given distance from leaf nodes.
int printKDistantfromLeaf(Node* root, int k)
{
    ret.clear(); mp.clear();
    helper(root,"");
    int res = 0;
    for(string s : ret){
        if(s.length() < k)
            continue;
        else{
            Node *temp  = root;
            for(int i = 0; i < s.length() - k; i ++){
                if(s[i] == 'l'){
                    temp = temp->left;
                }
                else{
                    temp = temp->right;
                }
            }
            if(mp.find(temp) == mp.end()){
                mp[temp]++;
                res++;
            }
        }
    }
    return res;
}
