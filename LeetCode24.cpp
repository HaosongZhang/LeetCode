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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL)   return head; // 没有结点或只有一个结点
        
        ListNode *p1 = head;
        ListNode *p2 = head->next;
        ListNode *p3 = NULL;
        
        ListNode *temp = head->next; // 交换后的头结点为原链表的第二个结点
        head = new ListNode(0); // 新建哨兵结点方便操作

        while (1)
        {
            p3 = p2->next;
            
            p2->next = p1;  // 第一步，交换结点
            head->next = p2;    // 第二步，连接交换后的两个结点到新链表中
            head = p1;  // 第三步，指向新链表尾结点
            head->next = p3;    // 第四步，连接原链表后面的结点到新链表中
            
            if (p3 && p3->next)
            {
                p1 = p3;
                p2 = p1->next;
            }
            else
            {
                break;
            }    
        }
        
        return temp;
        
    }
};
