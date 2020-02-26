/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    struct ListNode *fast_p=head,*slow_p=head;
    while(fast_p!=0&&fast_p->next!=0){
        slow_p=slow_p->next;
        fast_p=fast_p->next->next;
        if(slow_p==fast_p) return 1;
    }
    return 0;
}
