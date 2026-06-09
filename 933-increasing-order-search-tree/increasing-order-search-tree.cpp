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
    TreeNode* prev = nullptr;
    TreeNode* newRoot = nullptr;

    void inorder(TreeNode* node) {
        if(!node)
            return;
        
        inorder(node->left);

        node->left = nullptr;

        if(!prev) 
            newRoot = node;
        else
            prev->right = node;
        prev = node;

        inorder(node->right);
    }

    TreeNode* increasingBST(TreeNode* root) {
        inorder(root);
        return newRoot;
    }
};
