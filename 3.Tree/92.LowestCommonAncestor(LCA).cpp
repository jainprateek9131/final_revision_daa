class Solution
{
    public:
    //Function to return the lowest common ancestor in a Binary Tree.
     bool helper(Node* root, int val, vector<Node*>& ans){
     if(root==NULL){
         return false;
     }
     if(root->data==val){
         ans.push_back(root);
         return true;
     }
     bool left = helper(root->left,val,ans);
     if(left){
         ans.push_back(root);
         return true;
     }
     bool right = helper(root->right,val,ans);
     if(right){
         ans.push_back(root);
         return true;
     }
     return false;
    }
 

    Node* lca(Node* root ,int n1 ,int n2 )
    {
       //Your code here 
       vector<Node*> v1;
       vector<Node*> v2;
       helper(root,n1,v1);
       helper(root,n2,v2);
       int i=v1.size()-1;
       int j=v2.size()-1;
       while(i>=0 and j>=0 and v1[i]==v2[j]){
           i--;j--;
       }i++;j++;
       return v1[i];
       
    }
};
