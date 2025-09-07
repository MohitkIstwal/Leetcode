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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // using priority queue
        priority_queue<int,vector<int>,greater<int>> minheap;

        for (int i = 0; i < lists.size(); i++) {
            ListNode* node = lists[i];
            while (node != nullptr) {
                minheap.push(node->val);
                node = node->next;
            }
        }
        if (minheap.empty()) return nullptr;
        ListNode* ans=new ListNode(minheap.top());
        minheap.pop();
        ListNode* temp=ans;
        while(!minheap.empty()){
            ListNode* a=new ListNode(minheap.top());
            temp->next=a;
            temp=temp->next;
            minheap.pop();
        }
        return ans;
    }
};