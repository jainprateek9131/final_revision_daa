class Solution
{
    public: 
    //Function to convert binary tree to doubly linked list and return it.
    Node * head=NULL,*prev=NULL;
    void helper(Node*root){
        if(root==NULL)return;
        helper(root->left);
        if(prev==NULL){
            head = root;
        }else{
            prev->right=root;
            root->left=prev;
        }
        prev=root;
        helper(root->right);
    }
    Node * bToDLL(Node *root)
    {
        // your code here
        helper(root);
        return head;
    }
};
