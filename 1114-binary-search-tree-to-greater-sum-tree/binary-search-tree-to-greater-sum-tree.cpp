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
    vector<int> ele;

    void traverseTree(TreeNode* root) {
        if(!root)
            return;
        
        traverseTree(root->left);
        ele.push_back(root->val);
        traverseTree(root->right);
    }

    int idx = 0;
    void traverseTree2(TreeNode* root) {
        if(!root)
            return;
        
        traverseTree2(root->left);
        root->val = ele[idx];
        idx++;
        traverseTree2(root->right); 
    }

    TreeNode* bstToGst(TreeNode* root) {
        traverseTree(root);

        for(int i = ele.size() - 2; i >= 0; i--)
            ele[i] += ele[i + 1];
        
        traverseTree2(root);

        return root;
    }
};