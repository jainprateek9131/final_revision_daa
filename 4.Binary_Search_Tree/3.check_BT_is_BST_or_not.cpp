-----------------Inorder traversal of a binary search tree is always in a sorted order!!---------------
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
-------------------------For each node, check if max value in left subtree is smaller than the node and min value in right subtree greater than the node.------
  
