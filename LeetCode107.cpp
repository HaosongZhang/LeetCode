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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> vec;
        queue<TreeNode *> que;
        que.push(root);
        que.push(NULL);
        int i = 0;
        while(!que.empty()) {
            if(que.front() == NULL) break;
            vector<int> t;
            while(que.front() != NULL) {
                TreeNode *p = que.front();
                que.pop();
                t.push_back(p->val);
                if(p->left != NULL) que.push(p->left);
                if(p->right != NULL) que.push(p->right);
            }
            vec.push_back(t);
            que.pop();
            que.push(NULL);
            i++;
        }
        reverse(vec.begin(), vec.end());
        return vec;
    }
};
