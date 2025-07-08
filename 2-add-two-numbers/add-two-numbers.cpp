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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *sumlist=new ListNode(-1);
        ListNode *temp=sumlist;  
        int a,b,carry=0,c;
        while(l2 || l1){
            a=0; b=0;
            if(l1!=NULL){
                a=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL){
                b=l2->val;
                l2=l2->next;
            }
            c=a+b+carry;
            if(c>=10){
                carry=1;
                c-=10;
            }
            else{
                carry=0;
            }
            ListNode *t=new ListNode(c);
            temp->next=t;
            temp=temp->next;
        }
        if(carry==1){
            ListNode *t=new ListNode(1);
            temp->next=t;
            temp=temp->next;
        }
        return sumlist->next;
    }
};