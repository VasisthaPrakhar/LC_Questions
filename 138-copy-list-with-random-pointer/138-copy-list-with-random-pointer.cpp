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
        if(head==nullptr){
            return head;
        }
        Node *temp,*ans;
        int f=1;
        unordered_map<Node*,Node*>m;
        while(head){
            if(m.find(head)==m.end()){
                m[head]=new Node(head->val);
            }
            Node *t=m[head];
            if(head->random){
                if(m.find(head->random)==m.end()){
                    Node* t1=new Node(head->random->val);
                    m[head->random]=t1;
                }
                t->random=m[head->random];
            }
            if(f){
                ans=t;
                temp=t;
                f--;
            }else{
                temp->next=t;
                temp=temp->next;
            }
            head=head->next;
        } 
        return ans;
    }
};