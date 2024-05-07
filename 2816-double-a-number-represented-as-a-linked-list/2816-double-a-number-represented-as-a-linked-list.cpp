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
    ListNode* reverse(ListNode* temp){
        ListNode* prev=NULL;
        while(temp){
            auto t=temp->next;
            temp->next=prev;
            prev=temp;
            temp=t;
        }
        return prev;
    }
    ListNode* doubleIt(ListNode* head) {
        auto h=reverse(head);
        int c=0;
        auto temp=h;
        while(h->next!=nullptr){
            int k=h->val*2 + c;
            int v=k%10;
            c=k/10;
            h->val=v;
            h=h->next;
        }
        int k=h->val*2 + c;
            int v=k%10;
            c=k/10;
            h->val=v;
        if(c>0){
            h->next=new ListNode(c);
        }
        ListNode* ans=reverse(temp);
        return ans;
    }
};