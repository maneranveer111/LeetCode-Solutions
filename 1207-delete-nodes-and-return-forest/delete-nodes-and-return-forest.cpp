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
    vector<TreeNode*> ans; 
    unordered_set<int> st;

    void print(TreeNode* root) {
        if(!root)
            return;
        print(root->left);
        print(root->right);

        cout << root-> val << " ";
    }

    TreeNode* helper(TreeNode* root, bool isRoot) {
        if(!root)   
            return nullptr;
        
        bool deleted = st.count(root->val);

        if(isRoot && !deleted) {
            ans.push_back(root);
            print(root);
            cout << endl;
        }

        root->left = helper(root->left, deleted);
        root->right = helper(root->right, deleted);

        return (deleted) ? nullptr : root;
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        st.insert(to_delete.begin(), to_delete.end());

        helper(root, true);
        
        return ans;
    }
};