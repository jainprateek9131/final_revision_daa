Given a Binary Search Tree and a target sum. Check whether there's a pair of Nodes in the BST with value summing up to the target sum. 

Example 1:

Input:
        2
      /   \
     1     3
sum = 5
Output: 1 
Explanation: 
Nodes with value 2 and 3 sum up to 5.
Example 2:

Input:
           6
          /    
         5     
        /
       3 
     /  \
    1    4
sum = 2
Output: 0 
Explanation: 
There's no pair that sums up to 2.

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
optimal :This can be done without extra space given that we are allowed to modify the tree.

Convert BST to sorted doubly linked list (via in order traversal) and then apply 2 sum.
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
    int isPairPresent(struct Node *root, int target)
    {
        helper(root);
        Node* h = head, *t= prev;
        while(h->data<t->data){
            if(h->data+t->data==target){
                return true;
            }
            else if(h->data+t->data<target){
                h=h->right;
            }else if(h->data+t->data>target){
                t=t->left;
            }
        }
        return false;
    }
