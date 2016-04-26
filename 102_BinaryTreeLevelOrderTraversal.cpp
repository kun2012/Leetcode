/****************************************************************
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode *> q1, q2;
        vector<vector<int> > res;
        
        if (!root) return res;
        
        q1.push(root);
        while(true) {
            vector<int> vec;
            while(!q1.empty()) {
                TreeNode *t = q1.front();
                q1.pop();
                vec.push_back(t->val);
                if (t->left) q2.push(t->left);
                if (t->right) q2.push(t->right);
            }
            res.push_back(vec);
            if (q2.empty()) break;
            swap(q1, q2);
        }
        return res;
    }
};