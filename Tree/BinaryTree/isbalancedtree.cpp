class Solution
{
public:
    int ans = 0;
    int height(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }
        int x, y;
        x = height(root->left);
        y = height(root->right);
        if (abs(x - y) > 1)
        {
            ans = 1;
        }
        return max(x, y) + 1;
    }
    bool isBalanced(TreeNode *root)
    {
        int l = height(root);
        if (ans == 0)
        {
            return true;
        }
        return false;
    }
};