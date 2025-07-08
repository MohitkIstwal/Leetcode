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
        //Brute Approach (Adding Nodes in a map DS)
        if(head==NULL){
            return NULL;
        }
        ListNode *temp=head;
        map<ListNode *,int> mp;
        while(temp){
            if(mp.find(temp)!=mp.end()){
                return temp;
            }
            mp[temp]=1;
            temp=temp->next;
        }
        return NULL;
    }
};