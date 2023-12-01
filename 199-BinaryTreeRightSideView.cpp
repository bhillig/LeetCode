 // 199 - Binary Tree Right Side View (LeetCode Exercise)
 
 // Time Complexity: O(n) since we process each node once
 // Space Complexity: O(n) since we create a queue at worst of size n

 #include <vector>
 #include <deque>

 struct TreeNode 
 {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
 std::vector<int> rightSideView(TreeNode* root) 
{
    std::vector<int> res;

    std::deque<TreeNode*> queue;
    queue.push_front(root);

    while (!queue.empty())
    {
        int queueLength = queue.size();
        TreeNode* rightMostNode = nullptr;

        for (int i = 0; i < queueLength; ++i)
        {
            TreeNode* node = queue.front();
            queue.pop_front();

            if (node)
            {
                rightMostNode = node;
                queue.push_back(node->left);
                queue.push_back(node->right);
            }
        }

        if (rightMostNode)
        {
            res.push_back(rightMostNode->val);
        }
    }

    return res;
}