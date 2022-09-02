class Solution {
  public:
    // Function to return the diameter of a Binary Tree.
    int res=0;
    int height(Node* root){
        if(root==NULL)return 0;
        int lh = height(root->left);
        int rh = height(root->right);
        res = max(res,lh+rh+1);
        return max(lh,rh)+1;
    }
    int diameter(Node* root) {
        height(root);
        return res;
    }
};
