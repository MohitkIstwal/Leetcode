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
    ListNode* getknode(ListNode* temp,int k){
        k-=1;
        while(temp!=NULL && k>0){
            k--;
            temp=temp->next;
        }
        return temp;
    }

    void reversell(ListNode* head){
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* next=NULL;
        while(curr){
            next=curr->next;
            curr->next=prev;
            prev=curr; curr=next;
        }
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* prevNode=NULL;
        ListNode* nextNode=NULL;
        while(temp!=NULL){
            ListNode* knode=getknode(temp,k);
            if(knode==NULL){
                if(prevNode){
                    prevNode->next=temp;
                }
                break;
            }
            else{
                nextNode=knode->next;
                knode->next=NULL;
                reversell(temp);
                if(temp==head){
                    head=knode;
                }
                else{
                    prevNode->next=knode;
                }
                prevNode=temp;
                temp=nextNode;
            }
        }
        return head;
    }
};