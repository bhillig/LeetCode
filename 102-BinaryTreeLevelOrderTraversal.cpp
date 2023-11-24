// 102 - Binary Tree Level Order Traversal (LeetCode Exercise)

// Time Complexity: O(n)
// Space Complexity for Solution 1: O(n) where n is the size of the queue
// Space Complexity for Solution 2: O(h) where h is the height of the tree

#include <vector>
#include <queue>

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Solution 1: BFS using queue

std::vector<std::vector<int>> levelOrder(TreeNode* root) 
{
    std::vector<std::vector<int>> result;
    std::queue<TreeNode*> queue;

    queue.push(root);

    int queueLength = queue.size();
    while (!queue.empty())
    {
        queueLength = queue.size();
        std::vector<int> level;
        for (int i = 0; i < queueLength; ++i)
        {
            TreeNode* node = queue.front();
            queue.pop();

            if (!node) continue;

            level.push_back(node->val);
            queue.push(node->left);
            queue.push(node->right);
        }
        
        if (level.empty()) continue;
        result.push_back(level);
    }

    return result;
}

// Solution 2: DFS

int getHeight(TreeNode* root)
    {
        if (!root) return 0;

        return 1 + std::max(getHeight(root->left), getHeight(root->right));
    }

    void traverseLevelOrder(TreeNode* root, int height, std::vector<std::vector<int>>& result)
    {
        if (!root) return;

        result[height].push_back(root->val);

        traverseLevelOrder(root->left, height + 1, result);
        traverseLevelOrder(root->right, height + 1, result);
    }

    std::vector<std::vector<int>> levelOrder(TreeNode* root) 
    {
        int height = getHeight(root);
        std::vector<std::vector<int>> result(height);   
        traverseLevelOrder(root, 0, result);
        return result; 
    }