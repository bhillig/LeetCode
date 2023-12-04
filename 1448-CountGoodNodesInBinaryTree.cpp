// 1448 - Count Good Nodes in Binary Tree (LeetCode Exercise)

// Time Complexity: O(n) as we visit each node once
// Space Complexity: O(log(n)) as our function stack gets as high as the height of the tree given

#include <algorithm>

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int getNumberOfGoodNodes(TreeNode* root, int max)
{
    int res = 0;

    if (!root) return res;

    if (root->val >= max) ++res;

    max = std::max(root->val, max);

    res += getNumberOfGoodNodes(root->left, max);
    res += getNumberOfGoodNodes(root->right, max);
    
    return res;
}

int goodNodes(TreeNode* root) 
{
    return getNumberOfGoodNodes(root, INT_MIN);
}