//Function to return a list containing elements of left view of the binary tree.
void helper(Node* root, vector<int>& ans,map<int,Node*>& m,int level){
    if(root == NULL)return;
    if((m[level]) == NULL){
        ans.push_back(root->data);
        m[level]=root;
    }
    helper(root->left,ans,m,level+1);
    helper(root->right,ans,m,level+1);
}
vector<int> leftView(Node *root)
{
   // Your code here
   vector<int> ans;
   map<int,Node*> m;
   helper(root,ans,m,0);
   return ans;
}
