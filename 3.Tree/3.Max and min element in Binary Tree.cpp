class Solution
{
public:
    int findMax(Node *node)
    {
        //code here
        if(node == NULL)return INT_MIN;
        return max(max(findMax(node->left),findMax(node -> right)),node->data);
    }
    int findMin(Node *node)
    {
        //code here
        if(node == NULL)return INT_MAX;
        return min(min(findMin(node->left),findMin(node -> right)),node->data);
    }
};
