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
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
        ListNode *dummy=new ListNode(-1);
        ListNode *temp=dummy;
        ListNode *t1=head1;
        ListNode *t2=head2;
        while(t1!=NULL && t2!=NULL){
            if(t1->val<=t2->val){
                temp->next=t1;
                t1=t1->next;
                temp=temp->next;
            }
            else{
                temp->next=t2;
                t2=t2->next;
                temp=temp->next;
            }
        }
        if(t1){
            temp->next=t1;
        }
        if(t2){
            temp->next=t2;
        }
        return dummy->next;
    }
};