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
int ans = 0;
    int height(TreeNode* p){
        if(p == NULL) return 0;
        int leftHT = height(p->left);
        int rightHT =  height(p->right);
        ans = max( ans, leftHT + rightHT);
        return max(leftHT, rightHT) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        // if(root == NULL) return 0;
        // int leftDiameter = diameterOfBinaryTree(root->left);
        // int rightDiameter = diameterOfBinaryTree(root->right);
        // int currDiameter = height(root->left) + height(root->right);

        // return max(currDiameter, max(leftDiameter, rightDiameter));
        height(root);
        return ans;
    }
};