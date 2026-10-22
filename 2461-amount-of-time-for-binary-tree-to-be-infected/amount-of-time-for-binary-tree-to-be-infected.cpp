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
    unordered_map<TreeNode*, TreeNode*> mp;

    void findParent(TreeNode* child, TreeNode* parent) {
        if(!child)
            return;
        
        mp[child] = parent;
        
        if(child->left)
            findParent(child->left, child);
        if(child->right)
            findParent(child->right, child);
    }

    TreeNode* findNode(TreeNode* node, int start) {
        if(!node)
            return nullptr;
        
        if(node->val == start)
            return node;
        
        TreeNode* lft = findNode(node->left, start);
        if(lft)
            return lft;
        
        TreeNode* rht = findNode(node->right, start);

        return rht;
    }

    int amountOfTime(TreeNode* root, int start) {
        if(!root)
            return 0;
        
        findParent(root, nullptr);
        unordered_set<TreeNode*> vis;

        TreeNode* node = findNode(root, start);

        if(!node)
            return 0;
        
        int minutes = 0;

        queue<TreeNode*> q;

        q.push(node);
        vis.insert(node);

        while(!q.empty()) {
            int sz = q.size();
            minutes++;


            for(int i = 0; i < sz; i++) {
                TreeNode* tmp = q.front();
                q.pop();


                if(tmp != nullptr && tmp->left != nullptr && !vis.count(tmp->left)) {
                    q.push(tmp->left);
                    vis.insert(tmp->left);
                }
                if(tmp != nullptr && tmp->right && !vis.count(tmp->right)) {
                    q.push(tmp->right);
                    vis.insert(tmp->right);
                }
                
                if(mp[tmp] != nullptr && !vis.count(mp[tmp])) {
                    vis.insert(mp[tmp]);
                    q.push(mp[tmp]);
                }
             }
        }


        return minutes - 1;
    }
};