// 572 - Subtree of Another Tree (LeetCode Exercise)

// Time Complexity: O(|r| * |s|) since for each node in our root tree, we compare it to all subtree nodes
// Space Complexity: O(n) in the worst case if the tree is completely unbalanced

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isSameTree(TreeNode* one, TreeNode* two)
{
    if (!one && !two) return true;
    
    if (one && two && one->val == two->val)
    {
        return isSameTree(one->left, two->left) && isSameTree(one->right, two->right);
    }
    
    return false;
}

bool isSubtree(TreeNode* root, TreeNode* subRoot) 
{
    if (!subRoot) return true;
    if (!root) return false;

    if (root->val == subRoot->val && isSameTree(root, subRoot))
    {
        return true;
    }

    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}