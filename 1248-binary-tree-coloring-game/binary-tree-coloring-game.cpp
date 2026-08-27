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
    int leftCount = 0, rightCount = 0;

    int countNodes(TreeNode* node, int x) {
        if (node == nullptr) 
            return 0;

        int left = countNodes(node->left, x);
        int right = countNodes(node->right, x);

        if (node->val == x) {
            leftCount = left;
            rightCount = right;
        }

        return left + right + 1;
    }

    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        countNodes(root, x);

        int parentCount = n - leftCount - rightCount - 1;

        int half = n / 2; 

        return (leftCount > half) || (rightCount > half) || (parentCount > half);
    }
};