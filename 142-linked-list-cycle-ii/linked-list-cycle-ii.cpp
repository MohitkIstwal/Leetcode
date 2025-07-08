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
    ListNode *detectCycle(ListNode *head) {
        // Tortoise and Hare Approach
        if(head==NULL || head->next==NULL){
            return NULL;
        }
        ListNode *slow=head;
        ListNode *fast=head;
        ListNode *temp=NULL;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                temp=slow; slow=head; break;
            }
        }
        if(temp!=NULL){
            while(true){
                if(slow==temp){
                    return temp;
                }
                slow=slow->next;
                temp=temp->next;
            }
        }
        return NULL;
    }
};