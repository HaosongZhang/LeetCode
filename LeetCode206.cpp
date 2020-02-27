/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){
    struct ListNode *p = head, *q;
    head = NULL;
    while(p) {
        q = p->next;
        p->next = head;
        head = p;
        p = q;
    }
    return head;
}
