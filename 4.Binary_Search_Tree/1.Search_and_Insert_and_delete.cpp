bool search(struct Node* root, int x) {
    if(root==NULL)return false;
    else if(root->data==x)return true;
    else if(root->data<x)search(root->right,x);
    else search(root->left,x);
}
Given a BST and a key K. If K is not present in the BST, Insert a new Node with a value equal to K into the BST. 
Note: If K is already present in the BST, don't modify the BST.
Node* insert(Node* root, int key) {
    // Your code here
    //if(search(root,key))return root;
    struct Node* node=root,*parent=NULL;
    while(node!=NULL){
        parent = node;
        if(key == node->data){
            return root;
        }else if(key > node->data){
            node=node->right;
        }else if(key<node->data){
            node = node->left;
        }
    }
    if(parent->data<key)parent->right=new Node(key);
    else parent->left=new Node(key);
    return root;
}
//recursion
Node* insert(Node* root, int key) {
    if(root==NULL){
        Node* t = new Node(key);
        return t;
    }else if(root->data<key){
        root->right=insert(root->right,key);
    }
    else if(root->data>key){
        root->left=insert(root->left,key);
    }else return root;
}
