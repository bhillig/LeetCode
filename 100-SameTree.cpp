// 100 - Same Tree (LeetCode Exercise)

// Idea here is to break it into subproblems of checking 
// whether two nodes are the same, if they are check if
// both the left and right children are the same. If at
// anytime they aren't return false, else they are the same tree

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isSameTree(TreeNode* p, TreeNode* q) 
{
    if(p && !q || !p && q) return false;

    if(!p && !q) return true;

    if(p->val == q->val)
    {
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }

    return false;
}