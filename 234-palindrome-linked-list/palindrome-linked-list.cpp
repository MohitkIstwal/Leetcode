/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head->next==NULL){
            return true;
        }
        ListNode *slow=head;
        ListNode *fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        if(fast){
            slow=slow->next;
        }
        ListNode *prev=NULL;
        ListNode *cur=slow;
        ListNode *aage=NULL;
        while(cur){
            aage=cur->next;
            cur->next=prev;
            prev=cur; cur=aage;
        }
        ListNode *second=prev;
        ListNode *temp=head;
        while(prev!=NULL){
            if(prev->val!=temp->val){
                return false;
            }
            prev=prev->next; temp=temp->next;
        }
        return true;
    }
};