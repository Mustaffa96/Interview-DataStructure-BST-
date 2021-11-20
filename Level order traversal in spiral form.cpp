/*
Complete the function to find spiral order traversal of a tree. For below tree, function should return 1, 2, 3, 4, 5, 6, 7.


 
 

Example 1:

Input:
      1
    /   \
   3     2
Output:1 3 2

Example 2:

Input:
           10
         /     \
        20     30
      /    \
    40     60
Output: 10 20 30 60 40 
Your Task:
The task is to complete the function findSpiral() which takes root node as input parameter and returns the elements in spiral form of level order traversal as a list. The newline is automatically appended by the driver code.
Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
0 <= Number of nodes <= 105
0 <= Data of a node <= 105
*/

/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */


//Function to return a list containing the level order traversal in spiral form.
vector<int> findSpiral(Node *root)
{
    vector<int> v;
    int level=0;
    if(root==NULL){
        return v;
    }
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int size=q.size(); 
        vector<int> temp;
        for(int i=0;i<size;i++){
            Node* r=q.front();
            q.pop();
            temp.push_back(r->data);
            if(r->left){
                q.push(r->left);
            }
            if(r->right){
                q.push(r->right);
            }
        }
        if(level%2==0){
            reverse(temp.begin(),temp.end());
        }
        for(int i=0;i<temp.size();i++){
            v.push_back(temp[i]);
        }
        level++;
    }
    return v;
}
