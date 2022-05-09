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
    int idx;
    int ans;
    void solve(TreeNode* node, int k){
        if(!node || ans != -1) return;
        
        solve(node->left, k);
        ++idx;
        
        if(idx == k){ ans = node->val; return; }
        
        solve(node->right, k);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        idx = 0;
        ans = -1;
        solve(root, k);
        return ans;
    }
};