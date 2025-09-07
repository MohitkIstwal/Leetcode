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
class compare{
    public:
        bool operator()(ListNode *a,ListNode *b){
            return a->val>b->val;
        }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*> &arr){
        // Priority Queue Solution

        priority_queue<ListNode* ,vector<ListNode*>, compare> pq;
    

        for(int i=0;i<arr.size();i++){
            if(arr[i] != NULL) pq.push(arr[i]);
        }
        ListNode *dummy=new ListNode(-1);
        ListNode *c=dummy;

        while(!pq.empty()){
            ListNode* temp=pq.top();
            pq.pop();
            c->next=temp;
            c=c->next;

            if(temp->next!=NULL){
                pq.push(temp->next);
            }
        }
        return dummy->next;
    }
};