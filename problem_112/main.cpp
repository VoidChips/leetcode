#include <iostream>
using namespace std;

// Definition for a binary tree node.
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
    void _hasPathSum(TreeNode *root, const int &sum, int curr_sum, bool &pathExists)
    {
        if (root == nullptr || pathExists)
        {
            return;
        }

        curr_sum += root->val;
        _hasPathSum(root->left, sum, curr_sum, pathExists);
        // the last node added is the leaf
        if (curr_sum == sum && root->left == nullptr && root->right == nullptr)
        {
            pathExists = true;
        }
        _hasPathSum(root->right, sum, curr_sum, pathExists);
    }

public:
    bool hasPathSum(TreeNode *root, int sum)
    {
        bool pathExists{false};
        _hasPathSum(root, sum, 0, pathExists);
        return pathExists;
    }

    void _clear(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }

        _clear(root->left);
        _clear(root->right);
        delete root;
    }

    void clear(TreeNode *root)
    {
        _clear(root);
    }
};

int main()
{
    TreeNode *n1{new TreeNode(5)};
    TreeNode *n2{new TreeNode(4)};
    TreeNode *n3{new TreeNode(8)};
    TreeNode *n4{new TreeNode(11)};
    TreeNode *n5{new TreeNode(13)};
    TreeNode *n6{new TreeNode(4)};
    TreeNode *n7{new TreeNode(7)};
    TreeNode *n8{new TreeNode(2)};
    TreeNode *n9{new TreeNode(1)};
    Solution a;

    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n3->left = n5;
    n3->right = n6;
    n4->left = n7;
    n4->right = n8;
    n6->right = n9;

    cout << boolalpha;
    cout << a.hasPathSum(n1, 22) << endl;
    a.clear(n1);

    n1 = new TreeNode(1);
    n2 = new TreeNode(2);
    n1->left = n2;

    cout << a.hasPathSum(n1, 1) << endl;
    a.clear(n1);

    return 0;
}