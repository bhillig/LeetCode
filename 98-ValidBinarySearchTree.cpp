// 98 - Valid Binary Search Tree (LeetCode Exercise)

// Main idea behind this approach is to keep track of a min and max value
// When we go to a node's right child the minimum becomes the node's value
// When we go to a node's left child the maximum becomes the node's value
// Else the min/max stay the same

// Time Complexity: O(n) where n is the number of nodes in the tree given
// Space Complexity: O(h) since the maximum depth of our recursive calls is h where h is the height of the tree given

#include <limits>

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isValid(TreeNode* root, long long min, long long max)
{
    if (!root) return true;

    if (root->val >= max) return false;
    if (root->val <= min) return false;

    return isValid(root->left, min, root->val) && isValid(root->right, root->val, max);
}

bool isValidBST(TreeNode* root) 
{
    return isValid(root, LONG_MIN, LONG_MAX);
}