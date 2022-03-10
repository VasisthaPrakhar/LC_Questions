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
        ListNode *ans=new ListNode(-1);
        ListNode *res=ans;
        while(l1 && l2){
            int temp=l1->val+l2->val+c;
            ListNode* t=new ListNode(temp%10);
            c=temp/10;
            ans->next=t;
            ans=ans->next;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1){
            int temp=l1->val+c;
            ListNode* t=new ListNode(temp%10);
            c=temp/10;
            ans->next=t;
            ans=ans->next;
            l1=l1->next;
        }
        while(l2){
            int temp=l2->val+c;
            ListNode* t=new ListNode(temp%10);
            c=temp/10;
            ans->next=t;
            ans=ans->next;
            l2=l2->next;
        }
        if(c){
            ListNode* t=new ListNode(c);
            ans->next=t;
        }
        return res->next;
    }
};