/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // Using map . space complexity will be used.
        if(head==NULL){
            return NULL;
        }
        // if(head->next==NULL){
        //     Node *temp=new Node(head->val);
        //     return temp;
        // }
        Node *temp=head;
        map<Node*, Node*> mp;
        while(temp){
            Node *t=new Node(temp->val);
            mp[temp]=t;
            temp=temp->next;
        }
        temp=head;
        while(temp){
            Node *copyNode=mp[temp];
            copyNode->next=mp[temp->next];
            copyNode->random=mp[temp->random];
            temp=temp->next;
        }
        return mp[head];
    }
};