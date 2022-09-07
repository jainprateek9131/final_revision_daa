Traverse tree and store each node in an element, if target-current element is already present return 1.
unordered_map <int,int> mp;
int ans = 0;
int isPairPresent(struct Node *root, int t){
    if(!root || ans) return 1;
    if(mp[t-root->data]) return ans = 1;
    mp[root->data]++;
    if(root->data < t) isPairPresent(root->right,t);
    isPairPresent(root->left,t);
    return ans;
}
set<int>s;
    int isPairPresent(struct Node *root, int target)
    {
        if(root==NULL)return false;
        if(isPairPresent(root->left,target))return true; 
        if(s.find(target-root->data)!=s.end())return true;
        s.insert(root->data);
        if(isPairPresent(root->right,target))return true;
        return false;
    }
