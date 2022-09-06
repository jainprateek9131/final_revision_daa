bool helper(TreeNode* root, int val, vector<int>& ans){
     if(root==NULL){
         return false;
     }
     if(root->val==val){
         ans.push_back(root->val);
         return true;
     }
     bool left = helper(root->left,val,ans);
     if(left){
         ans.push_back(root->val);
         return true;
     }
     bool right = helper(root->right,val,ans);
     if(right){
         ans.push_back(root->val);
         return true;
     }
     return false;
 }
 
vector<int> Solution::solve(TreeNode* a, int b) {
    vector<int> ans;
    helper(a,b,ans);
    reverse(ans.begin(),ans.end());
    return ans;
}
