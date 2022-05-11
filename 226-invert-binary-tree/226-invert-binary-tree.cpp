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
    void solve(TreeNode* mainTree, TreeNode* invertedTree){
        if(!mainTree)
            return;
        if(mainTree->left){
            invertedTree->right = new TreeNode(mainTree->left->val);
            solve(mainTree->left, invertedTree->right);
        }
        if(mainTree->right){
            invertedTree->left = new TreeNode(mainTree->right->val);
            solve(mainTree->right, invertedTree->left);
        }
        
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root)
            return root;
        TreeNode *invertedTree = new TreeNode(root->val);
        solve(root, invertedTree);
        return invertedTree;
    }
};