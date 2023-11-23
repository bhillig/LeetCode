// 543 - Diameter of Binary Tree (LeetCode Exercise)

// Time Complexity: O(n) where n is the number of nodes in the tree
// Space Complexity: O(h) where h is the height of the tree

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

int getMaxHeight(TreeNode* root, int& outDiameter)
{
    if (!root) return 0;

    int left = getMaxHeight(root->left, outDiameter);
    int right = getMaxHeight(root->right, outDiameter);
    outDiameter = std::max(outDiameter, left + right);
    return std::max(left, right) + 1;
}

int diameterOfBinaryTree(TreeNode* root) 
{
    int outDiameter = 0;
    getMaxHeight(root, outDiameter);
    return outDiameter;
}