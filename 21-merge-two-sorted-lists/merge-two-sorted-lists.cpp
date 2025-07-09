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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL && list2==NULL){
            return NULL;
        }
        if(list1==NULL){
            return list2;
        }
        if(list2==NULL){
            return list1;
        }
        ListNode *dummy=new ListNode(-1);
        ListNode *temp=dummy;
        ListNode *t1=list1;
        ListNode *t2=list2;
        while(t1 || t2){
            int a=1e9,b=1e9;
            if(t1){
                a=t1->val;
            }
            if(t2){
                b=t2->val;
            }
            if(a<=b){
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
        return dummy->next;
    }
};