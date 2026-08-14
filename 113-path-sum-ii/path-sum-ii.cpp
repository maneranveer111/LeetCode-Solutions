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
public:
    void dfs(TreeNode* root, int target, vector<vector<int>>& ans, vector<int>& currpath){
        if(root == nullptr) return;

        target -= root->val;
        currpath.push_back(root->val);

        if(root->left == nullptr && root->right == nullptr) {
            if(target == 0) ans.push_back(currpath); 
        }

        dfs(root->left, target, ans, currpath);
        dfs(root->right, target, ans, currpath);
        currpath.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> currpath;
        dfs(root, targetSum, ans, currpath);

        return ans;
    }
};