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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *left = head, *right = head;
        for(int i = 0; i < n; ++i) {
            right = right -> next;
        }	
        if(right == NULL) return head -> next;
        while(right -> next != NULL) {
            right = right -> next;
            left = left -> next;
        }
        left -> next = left -> next -> next;
		return head;
    }
};
