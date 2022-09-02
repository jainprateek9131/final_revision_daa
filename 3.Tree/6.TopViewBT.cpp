class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        vector<int> ans;
        if(root==NULL)return ans;
        queue<pair<int,Node*>>q;
        map<int,vector<int>>m;
        q.push({0,root});
        m[0].push_back(root->data);
        while(!q.empty()){
            pair<int,Node*>temp=q.front();
            q.pop();
            int index = temp.first;
            Node* node = temp.second;
            if(node->left!=NULL){
                m[index-1].push_back(node->left->data);
                q.push({index-1,node->left});
            }
            if(node->right!=NULL){
                m[index+1].push_back(node->right->data);
                q.push({index+1,node->right});
            }
        }
        for(auto it:m){
            ans.push_back(it.second[0]);
        }
        return ans;
    }
};
