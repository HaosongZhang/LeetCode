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
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        if(root->left == NULL && root->right == NULL) return 1;
        int mmin = 2147483647;
        if(root->left != NULL) {
            mmin = min(mmin, minDepth(root->left));
        }
        if(root->right != NULL) {
            mmin = min(mmin, minDepth(root->right));
        }
        return mmin + 1;
    }
};
