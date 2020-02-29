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
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        int mmax = 0;
        mmax = max(mmax, maxDepth(root->left));
        mmax = max(mmax, maxDepth(root->right));
        return mmax + 1;
    }
};
