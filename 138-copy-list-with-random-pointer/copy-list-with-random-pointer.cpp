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
        if(head==NULL){
            return NULL;
        }
        Node *temp=head;
        while(temp){
            Node *newNode=new Node(temp->val);
            newNode->next=temp->next; temp->next=newNode; 
            temp=newNode->next;
        }
        temp=head;
        while(temp){
            if(temp->random){
                temp->next->random=temp->random->next;
            }
            temp=temp->next->next;
        }
        Node* original = head;
        Node* copy = head->next;
        Node* newHead = copy;
        while (original && copy) {
            original->next = original->next->next;
            if(copy->next){
                copy->next=copy->next->next;
            }
            else{
                copy->next=NULL;
            }
            original = original->next;
            copy = copy->next;
        }
        return newHead;
    }
};