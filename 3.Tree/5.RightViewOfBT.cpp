void helper(Node* root, vector<int>& ans,map<int,Node*>& m,int level){
    if(root == NULL)return;
    if((m[level]) == NULL){
        ans.push_back(root->data); 
        m[level]=root;
    }
    helper(root->right,ans,m,level+1);
    helper(root->left,ans,m,level+1);
}
class Solution
{
    public:
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
       vector<int> ans;
       map<int,Node*> m;
       helper(root,ans,m,0);
       return ans;
    }
};

