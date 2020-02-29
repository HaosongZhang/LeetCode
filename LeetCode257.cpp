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
    vector<string> vec;
    string path;
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root) {
            return vec;
        }
        if(!root->left && !root->right) {
            path += to_string(root->val);
            vec.push_back(path);
            return vec;
        }
        path += to_string(root->val) +"->";
        string path2 = path;
        binaryTreePaths(root->left);
        path = path2;
        binaryTreePaths(root->right);
        path = path2;
        return vec; 
    }
};
