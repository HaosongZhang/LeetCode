/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeElements(struct ListNode* head, int val){
    struct ListNode *p = head;
    while(p && p->val == val) {
        p = p->next;
    }
    head = p;
    while (p && p->next) {
        if (p->next->val == val) {
            p->next = p->next->next;
        }
        else p = p->next;
    }
    return head;
}
