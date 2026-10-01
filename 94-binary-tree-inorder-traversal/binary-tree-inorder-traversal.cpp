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
    
    void inorderTravere(TreeNode* root, vector<int>& ans){
        if(root == nullptr) return;
        inorderTravere(root->left, ans);
        ans.push_back(root->val);
        inorderTravere(root->right, ans);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        // inorderTravere(root, ans);

        // return ans;
        TreeNode* curr = root;

        while(curr) {
            if(!curr->left) {
                ans.push_back(curr->val);
                curr = curr->right;
            }
            else {
                TreeNode* prec = curr->left;

                while(prec->right && prec->right != curr) {
                    prec = prec->right;
                }

                if(!prec->right) {
                    prec->right = curr;
                    curr = curr->left;
                }
                else {
                    prec->right = nullptr;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }

        }

        return ans;
    }
};