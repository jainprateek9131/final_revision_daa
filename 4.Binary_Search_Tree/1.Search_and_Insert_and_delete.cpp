bool search(struct Node* root, int x) {
    if(root==NULL)return false;
    else if(root->data==x)return true;
    else if(root->data<x)search(root->right,x);
    else search(root->left,x);
}
