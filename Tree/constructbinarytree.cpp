
#include <iostream>
#include <vector>
using namespace std;
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
    int findpos(vector<int> &inorder, int ele)
    {
        for (int i = 0; i < inorder.size(); i++)
        {
            if (inorder[i] == ele)
                return i;
        }
        return -1;
    }
    TreeNode *solve(vector<int> &inorder, vector<int> &postorder, int &index, int instart, int inend)
    {

        if (index < 0 || instart > inend)
            return NULL;
        int element = postorder[index--];
        TreeNode *root = new TreeNode(element);
        int pos = findpos(inorder, element);

        root->right = solve(inorder, postorder, index, pos + 1, inend);

        root->left = solve(inorder, postorder, index, instart, pos - 1);

        return root;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        int porder = postorder.size() - 1;
        TreeNode *ans = solve(inorder, postorder, porder, 0, inorder.size() - 1);
        return ans;
    }
};