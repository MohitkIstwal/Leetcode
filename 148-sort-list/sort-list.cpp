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
    ListNode* sortList(ListNode* head) {
        if(head==NULL){
            return NULL;
        }
        vector<int> v;
        ListNode *temp=head;
        while(temp){
            v.push_back(temp->val);
            temp=temp->next;
        }
        sort(v.begin(),v.end());
        ListNode *ans=new ListNode(v[0]);
        ListNode *t=ans;
        for(int i=1;i<v.size();i++){
            ListNode* a=new ListNode(v[i]);
            t->next=a;
            t=t->next;
        }
        return ans;
    }
};