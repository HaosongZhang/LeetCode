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
    int len(TreeNode *root) {
        if(root == NULL) return 0;
        return max(len(root->left), len(root->right)) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        int len1 = len(root->left), len2 = len(root->right);
        if(abs(len1 - len2) > 1) {
            return false;
        }
        return isBalanced(root->left) && isBalanced(root->right);
    }
};
