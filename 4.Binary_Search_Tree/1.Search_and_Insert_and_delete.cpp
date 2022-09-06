bool search(struct Node* root, int x) {
    if(root==NULL)return false;
    else if(root->data==x)return true;
    else if(root->data<x)search(root->right,x);
    else search(root->left,x);
}

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
