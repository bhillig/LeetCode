// 230 - Kth Smallest Element in a BST (LeetCode Exercise)

// Time Complexity: O(n) as we visit every node once
// Space Complexity: O(log(n)) as the stack size will be the height of the tree at worse for both Sol 1 and Sol 2

#include <stack>
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

// Solution 1 DFS - In Order Traversal

void inorderTraversal(TreeNode* root, std::vector<int>& values)
{
    if (!root) return;

    inorderTraversal(root->left, values);
    values.push_back(root->val);
    inorderTraversal(root->right, values);
}

int kthSmallest(TreeNode* root, int k) 
{
    std::vector<int> inorder;
    inorderTraversal(root, inorder);
    return inorder[k-1];
}

// Solution 2 - Iterative Approach w/ Stack

int kthSmallest(TreeNode* root, int k) 
{
    // add our current child to the stack
    // if the left node isnt null repeat
    std::stack<TreeNode*> stack;
    int n = 0;

    TreeNode* curr = root;

    while (!stack.empty() || curr)
    {
        while (curr)
        {
            stack.push(curr);
            curr = curr->left;
        }

        curr = stack.top();
        stack.pop();

        n += 1;
        if (n == k)
        {
            return curr->val;
        }
        curr = curr->right;
    }

    return -1;
}