
//Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int _maxDepth(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }

        int left_depth{1 + _maxDepth(root->left)};
        int right_depth{1 + _maxDepth(root->right)};
        return left_depth >= right_depth ? left_depth : right_depth;
    }

    int maxDepth(TreeNode *root)
    {
        return _maxDepth(root);
    }
};
