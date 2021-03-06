/****************************************************************
Given a binary tree, determine if it is height-balanced.
For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
****************************************************************/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int dfs(TreeNode *&p) {
        if (!p) return 0;
        int d1 = dfs(p->left);
        int d2 = dfs(p->right);
        if (d1 == -1 || d2 == -1) return -1;
        if (abs(d1 - d2) > 1) return -1;
        return max(d1, d2) + 1;
    }

    bool isBalanced(TreeNode* root) {
        if (dfs(root) != -1) return true;
        return false;
    }
};