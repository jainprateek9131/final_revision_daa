vector <int> bottomView(Node *root) {
        // Your Code Here
       //Your code here
        vector<int>ans;
        if(root==NULL)return ans;
        map<int,vector<Node*>>m;
        queue<pair<Node*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            pair<Node*,int> temp = q.front();
            q.pop();
            
                m[temp.second].push_back(temp.first);
            
            if(temp.first->left!=NULL){
                q.push({temp.first->left,temp.second-1});
            }
            if(temp.first->right!=NULL){
                q.push({temp.first->right,temp.second+1});
            }
        }
        for(auto it:m){
            ans.push_back(it.second[it.second.size()-1]->data);
        }
    }
