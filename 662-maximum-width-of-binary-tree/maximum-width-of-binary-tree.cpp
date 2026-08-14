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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        long long ans = 0;

        while(!q.empty()) {
            long long sz = q.size();
            long long start = q.front().second;
            long long en = start;

            for(int i = 0; i < sz; i++) {
                auto tm = q.front();
                TreeNode* curr = tm.first;
                long long idx = tm.second;
                en = idx;
                idx -= start;
                q.pop();

                if(curr->left)
                    q.push({curr->left, idx * 2});
                if(curr->right)
                    q.push({curr->right, idx * 2 + 1});
            }

            ans = max(ans, en - start + 1);
        }

        return ans;
    }
};