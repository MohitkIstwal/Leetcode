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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> mp(nums.begin(),nums.end());

        ListNode* dummy=new ListNode(-1,head);
        ListNode* prev=dummy;
        ListNode* t=head;

        while(t!=NULL){
            if(mp.count(t->val)){
                prev->next=t->next;
                t=t->next;
            }
            else{
                prev=t;
                t=t->next;
            }
        }
        return dummy->next;
    }
};