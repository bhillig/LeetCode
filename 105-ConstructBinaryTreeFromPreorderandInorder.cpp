// 105 - Construct Binary Tree from Preorder and Inorder Traversal (LeetCode Exercise)

// Time Complexity: O(n)
// Space Complexity: O(n)

#include <vector>

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) 
{
    if (preorder.empty() || inorder.empty()) return nullptr;

    TreeNode* root = new TreeNode(preorder[0]);
    int mid = std::find(inorder.begin(), inorder.end(), preorder[0]) - inorder.begin();

    std::vector<int> preorderLeft(preorder.begin()+1, preorder.begin() + mid + 1);
    std::vector<int> preorderRight(preorder.begin() + mid + 1, preorder.end());
    std::vector<int> inorderLeft(inorder.begin(), inorder.begin() + mid);
    std::vector<int> inorderRight(inorder.begin() + mid + 1, inorder.end());

    root->left = buildTree(preorderLeft, inorderLeft);
    root->right = buildTree(preorderRight, inorderRight);    
    return root;
}