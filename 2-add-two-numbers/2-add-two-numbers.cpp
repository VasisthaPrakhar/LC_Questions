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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int c=0;
        ListNode* ans=new ListNode(-1);
        ListNode* res=ans;
       while(l1 && l2){
           int k=l1->val+l2->val+c;
           c=k/10;
           ListNode *temp=new ListNode(k%10);
           res->next=temp;
           res=res->next;
           l1=l1->next;
           l2=l2->next;
       }
        while(l1){
            int k=l1->val+c;
           c=k/10;
           ListNode *temp=new ListNode(k%10);
            res->next=temp;
           res=res->next;
           l1=l1->next;
        }
        while(l2){
            int k=l2->val+c;
           c=k/10;
           ListNode *temp=new ListNode(k%10);
            res->next=temp;
           res=res->next;
           l2=l2->next;
        }
        if(c){
            ListNode *temp=new ListNode(c);
            res->next=temp;
        }
        return ans->next;
    }
};