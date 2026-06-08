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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mp;
        set<int> child;

        for(int i = 0; i < descriptions.size(); i++) {
            int par = descriptions[i][0];
            int cld = descriptions[i][1];
            int islft = descriptions[i][2];

            if(!mp.count(par)) {
                TreeNode* parent = new TreeNode(par);
                mp[par] = parent;
            }

            if(!mp.count(cld)) {
                TreeNode* temp = new TreeNode(cld);
                mp[cld] = temp;
            }

            if(islft == 1) {
                mp[par]->left = mp[cld];
            }
            else {
                mp[par]->right = mp[cld];
            }

            child.insert(cld);
        }

        for(int i = 0; i < descriptions.size(); i++) {
            int par = descriptions[i][0];
            if(!child.count(par))
                return mp[par];
        }

        return nullptr;
    }
};