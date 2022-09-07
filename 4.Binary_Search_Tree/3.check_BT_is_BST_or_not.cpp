Ques:Given the root of a binary tree. Check whether it is a BST or not.
Note: We are considering that BSTs can not contain duplicate Nodes.
A BST is defined as follows:

1.The left subtree of a node contains only nodes with keys less than the node's key.
2.The right subtree of a node contains only nodes with keys greater than the node's key.
3.Both the left and right subtrees must also be binary search trees.

Example 1:
Input:
   2
 /    \
1      3
Output: 1 
Explanation: 
The left subtree of root node contains node with key lesser than the root nodes key and the right subtree of root node contains node with key greater than 
the root nodes key. Hence, the tree is a BST.

soln 1:-----------------Inorder traversal of a binary search tree is always in a sorted order!!---------------
            50                            
           /     \        
          30      70     
            \    /  \                      
            40  60   80         
  Inorder Traversal:--- 40 30 50 60 70 80
void inorder(Node* root,vector<int> &v)
    {
       
        if(root==NULL)
        return ;
        inorder(root->left,v);
        v.push_back(root->data);
        inorder(root->right,v);
    }
    bool isBST(Node* root) 
    {
        // Your code here
        vector<int> v1,v2;
       inorder(root,v1);
       v2=v1;
       sort(v2.begin(),v2.end());
       if(v1==v2)
       return true;
       return false;
    }
soln 2: isGreater Element means the value of node is always greater then the value of keft subtree nodes and smaller then all right subtree nodes
ex:           50                            
           /     \        
          30      70     
            \    /  \                      
            40  60   80  ie 50 is greater then 30, 40 and  smaller then 70,60,80.
    public:
    //Function to check whether a Binary Tree is BST or not.
    bool isGreaterElement(Node* root,int node){
        if(root==NULL)return true;
        if(root->data < node and isGreaterElement(root->left,node)
           and isGreaterElement(root->right,node))return true;
        else return false;
    }
    bool isSmallerElement(Node* root,int node){
        if(root==NULL)return true;
        if(root->data > node and isSmallerElement(root->left,node)
           and isSmallerElement(root->right,node))return true;
        else return false;
    }
    bool isBST(Node* root) 
    {
        if(root==NULL)return true;
        if(isGreaterElement(root->left,root->data) and 
           isSmallerElement(root->right,root->data) and
           isBST(root->left) and isBST(root->right))return true;
        else return false;
    }
   };
soln 3: the maximum value in left subtree is smaller then node and mimum value in right subtree is greater then node
int maxInLeft(Node* root){
        //int max(left,right, root) int bt
        Node* maxE = root;
        if(maxE==NULL)return INT_MIN;
        while(root->right!=NULL){
            maxE = maxE->right;
            root=maxE;
        }
        return maxE->data;
    }
    int maxInRight(Node* root){
        Node* minE = root;
        if(minE==NULL)return INT_MAX;
        while(root->left!=NULL){
            minE = minE->left;
            root=minE;
        }
        return minE->data;
    }
    bool isBST(Node* root) 
    {
        if(root==NULL)return true;
        int left = maxInLeft(root->left);
        int right = maxInRight(root->right);
        if((root->data > left) and (root->data < right) and
           isBST(root->left) and isBST(root->right))return true;
        else return false;
    }
  final sol: we set limit for each ide like
   (-inf,+inf)           50 (-inf,+inf) value of  this node can lie between                           
   (-inf,+inf)        /     \        
  (-inf,+50)        30      70     
   (-inf,+inf)         \    /  \                      
     ( 30,+50)         40  60   80  
    (-inf,+inf)        / \    /  \   
    (-inf,+inf)      32    /  \   
    bool helper(Node* root, int min, int max){
        if(root==NULL)return true;
        if(root->data > min and root->data < max and
           helper(root->left, min , root->data) and
           helper(root->right, root->data , max))return true;
        return false;
    }
    bool isBST(Node* root) 
    {
        return helper(root,INT_MIN,INT_MAX);
    }
