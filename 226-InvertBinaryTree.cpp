// 226 - Invert Binary Tree (LeetCode Exercise)

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* invertTree(TreeNode* root)
{
    if(!root) return;

    // Invert this node
    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;

    // Invert its children
    invertTree(root->left);
    invertTree(root->right);

    return root;
}