/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        queue<int> que;
        stack<int> sta;
        ListNode* p = head;
        while (p) {
            que.push(p->val);
            sta.push(p->val);
            p = p->next;
        }
        while(!sta.empty() && !que.empty() && sta.top() == que.front()) {
            sta.pop();
            que.pop();
        }
        return empty(sta) && empty(que);
    }
};
