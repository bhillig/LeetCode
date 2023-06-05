// 104 - Maximum Depth of Binary Tree (LeetCode Exercise)

// Time Complexity: O(n)
// Space Complexity: O(n)

// General idea is to use DFS to go deep into our tree
// Once the base case is reached (a leaf node), we pop out returning
// the height level by level until we return back at the root

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

 int maxDepth(TreeNode* root)
 {
    if (!root) return 0;

    return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
 }