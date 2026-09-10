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
    int cnt = 0;

    pair<int, int> helper(TreeNode* root) {
        if(!root)
            return {0, 0};
        
        auto lft = helper(root->left);
        auto rht = helper(root->right);

        int total = root->val + lft.first + rht.first;
        int num = 1 + lft.second + rht.second;

        if(total / num == root->val)
            cnt++;
        
        return {total, num};
    }

    int averageOfSubtree(TreeNode* root) {
        auto tmp = helper(root);

        return cnt;
    }
};