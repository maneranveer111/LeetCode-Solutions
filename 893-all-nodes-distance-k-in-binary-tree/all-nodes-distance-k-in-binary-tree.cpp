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
    unordered_map<TreeNode*, TreeNode*> parent;
    void dfs(TreeNode* root, TreeNode* par) {
        if(root == nullptr) return;

        parent[root] = par;
        dfs(root->left, root);
        dfs(root->right, root);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        dfs(root, nullptr);
        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;
        q.push(target);
        visited.insert(target);
        int dis = 0;

        while(!q.empty()) {
            int size = q.size();
            
            if(dis == k) {
                vector<int> ans;
                while(!q.empty()) {
                    ans.push_back(q.front()->val);
                    q.pop();
                }
                return ans;
            }

            while(size--) {
                TreeNode* curr = q.front();
                q.pop();
                vector<TreeNode*> nbr = {curr->left, curr->right, parent[curr]};

                for(auto nb : nbr) {
                    if(nb && !visited.count(nb)) {
                        q.push(nb);
                        visited.insert(nb);
                    }
                }

            }
                dis++;

        }
            return {};
    }
};