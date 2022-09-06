1) -----------------------------------Node to be deleted is the leaf:----------------------
    Simply remove from the tree. 
                50                            50
           /     \         delete(20)      /   \
          30      70       --------->    30     70 
         /  \    /  \                     \    /  \ 
       20   40  60   80                   40  60   80
  2) --------------------------------Node to be deleted has only one child:--------------------- 
     Copy the child to the node and delete the child 

              50                            50
           /     \         delete(30)      /   \
          30      70       --------->    40     70 
            \    /  \                          /  \ 
            40  60   80                       60   80
    3)------------------------------ Node to be deleted has two children:-------------------------
      Find inorder successor of the node. Copy contents of the inorder successor to the node and delete the inorder successor.
      Note that inorder predecessor can also be used. 

              50 +                           60
           /     \         delete(50)      /   \
          40      70       --------->    40    70 
                 /  \                            \ 
                60   80                           80
      Inorder successor of above tree is---- 40 50 60 70 80 hence inorder successor of 50 is 60.
      The important thing to note is, inorder successor is needed only when the right child is not empty. In this particular case, inorder successor can be obtained by
      finding the minimum value in the right child of the node.
        Node* findMin(Node* root){
        Node* min = root;
        while(root->left!=NULL){
            root = root->left;
            min = root;
        }
        return min;
}
Node *deleteNode(Node *root, int x) {
    if(root==NULL)return NULL;
    else if(x<root->data){
        root->left = deleteNode(root->left,x);
    }else if(x>root->data){
        root->right = deleteNode(root->right,x);
    }else{// if(x == root->data)
        if(root->left==NULL && root->right==NULL){
            delete root;
            root=NULL;
        }else if(root->left==NULL){
            Node* temp = root;
            root=root->right;
            delete temp;
        }else if(root->right==NULL){
            Node* temp = root;
            root=root->left;
            delete temp;
        }else{
            Node* temp = findMin(root->right);
            root->data=temp->data;
            root->right = deleteNode(root->right,root->data);
        }
    }
    return root;
}
