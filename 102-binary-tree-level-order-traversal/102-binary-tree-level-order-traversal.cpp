/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    vector<vector<int>> ans;
    void solve(TreeNode* node, int level) {
        if (!node)
            return;
        if (level >= ans.size())
            ans.push_back(vector<int>());
        ans[level].push_back(node->val);
        solve(node->left, level + 1);
        solve(node->right, level + 1);
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)
            return ans;
        ans.push_back(vector<int>());
        solve(root, 0);
        return ans;
    }
};