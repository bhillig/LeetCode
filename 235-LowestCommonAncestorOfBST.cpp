// 235- Lowest Common Ancestor of Binary Search Tree (LeetCode Exercise)

// Time Complexity: O(log(n)) As for each level in our tree, we visit one node
// Space Complexity: O(1)

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
{
    TreeNode* curr = root;
    while (curr)
    {
        if (p->val > curr->val && q->val > curr->val)
        {
            curr = curr->right;
        }
        else if (p->val < curr->val && q->val < curr->val)
        {
            curr = curr->left;
        }
        else
        {
            return curr;
        }
    }    

    return nullptr;
}