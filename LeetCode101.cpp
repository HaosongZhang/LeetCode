/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool isMirror(struct TreeNode *p, struct TreeNode *q) {
    if(p == NULL && q == NULL) return true;
    else if(p == NULL || q == NULL) {
        return false;
    } else {
        return (p->val == q->val) && isMirror(p->right, q->left) && isMirror(p->left, q->right);
    }
}
bool isSymmetric(struct TreeNode* root){
    return isMirror(root, root);
}
