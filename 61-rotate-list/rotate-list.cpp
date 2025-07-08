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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode *temp=head;
        ListNode *lastnode;
        int n=0;
        while(temp){
            n++;
            if(temp->next==NULL){
                lastnode=temp;
            }
            temp=temp->next;
        }
        int a=k%n;
        if(a==0){
            return head;
        }
        int b=n-a-1; temp=head;
        for(int i=0;i<b;i++){
            temp=temp->next;
        }
        ListNode *newhead=temp->next;
        temp->next=NULL;
        lastnode->next=head;
        return newhead;
    }
};