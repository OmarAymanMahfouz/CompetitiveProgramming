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
    bool solve(TreeNode* root, TreeNode* sub){
        if (!root && !sub)
            return true;
        else if ((root && !sub) || (!root && sub))
            return false;

        
        if(root->val == sub->val){
            return solve(root->left, sub->left) & solve(root->right, sub->right);
        }
        
        return false;
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        vector<TreeNode*> vec;
        queue<TreeNode*> qu;
        qu.push(root);
        
        while(!qu.empty()){
            TreeNode* temp = qu.front();
            qu.pop();
            if(temp->val == subRoot->val)
                vec.push_back(temp);
            if(temp->left)
                qu.push(temp->left);
            if(temp->right)
                qu.push(temp->right);
        }
        
        for(int i = 0; i < vec.size(); i++){  
            if(solve(vec[i], subRoot))
                return true;
        }
        return false;
    }
};