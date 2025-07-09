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
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<int> v;
        ListNode *temp=head;
        while(temp){
            v.push_back(temp->val);
            temp=temp->next;
        }
        ListNode *newHead=new ListNode(-1);
        newHead->next=head;
        head=newHead;
        temp=head->next;
        int i=0;
        while(true){
            stack<int> st;
            int a=0;
            while(a!=k && i<v.size()){
                st.push(v[i]);
                i++; a++;
            }
            if(a==k){
                while(!st.empty()){
                    int x=st.top();
                    temp->val=x;
                    temp=temp->next;
                    st.pop();
                }
            }
            else{
                stack<int> st1;
                while(!st.empty()){
                    int x=st.top();
                    st1.push(x);
                    st.pop();
                }
                while(!st1.empty()){
                    int x=st1.top();
                    temp->val=x;
                    temp=temp->next;
                    st1.pop();
                }
                break;
            }
            if(i==v.size()){
                break;
            }
        }
        return head->next;
    }
};