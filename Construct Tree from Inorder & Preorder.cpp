/*
Given 2 Arrays of Inorder and preorder traversal. Construct a tree and print the Postorder traversal. 

Example 1:

Input:
N = 4
inorder[] = {1 6 8 7}
preorder[] = {1 6 7 8}
Output: 8 7 6 1
Example 2:

Input:
N = 6
inorder[] = {3 1 4 0 5 2}
preorder[] = {0 1 3 4 2 5}
Output: 3 4 1 5 2 0
Explanation: The tree will look like
       0
    /     \
   1       2
 /   \    /
3    4   5
Your Task:
Your task is to complete the function buildTree() which takes 3 arguments(inorder traversal array, preorder traversal array, and size of tree n) and returns the root node to the tree constructed. You are not required to print anything and a new line is added automatically (The post order of the returned tree is printed by the driver's code.)

Expected Time Complexity: O(N*N).
Expected Auxiliary Space: O(N).

Constraints:
1<=Number of Nodes<=1000
*/

class Solution{
    public:
    Node* buildTree(int in[],int pre[], int n)
    {
        n1=n;
        preIndex=0;
        return helper(in,pre,0,n-1);
    }
    private:
    int n1; int preIndex=0;
    Node* helper(int in[],int pre[],int start,int end)
    {
    
        if(start>end || end<0 || preIndex>=n1)   return NULL;
    
        int data=pre[preIndex++];
        Node* tNode = new Node(data);
        
        if (start==end)
            return tNode;
        int inIndex=search(in,start,end,data);
        
        tNode->left  = helper(in,pre,start,inIndex-1);
        tNode->right = helper(in,pre,inIndex+1,end);
        
        return tNode;
    }
    int search(int a[],int start,int end,int val)
    {
        for(int i=start; i<=end;i++)
        {
            if(a[i]==val)
                return i;
        }
    }
};
