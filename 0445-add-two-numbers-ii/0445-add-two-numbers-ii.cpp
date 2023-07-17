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
        stack<int>s2,s1;
        while(l1){
            s1.push(l1->val);
            l1=l1->next;
        }
        while(l2){
            s2.push(l2->val);
            l2=l2->next;
        }
        int c=0;
        ListNode *ans=nullptr;
        while(!s1.empty() && !s2.empty()){
            int temp=s1.top()+s2.top()+c;
            ListNode *t=new ListNode(temp%10);
            t->next=ans;
            ans=t;
            c=temp/10;
            s1.pop();
            s2.pop();
        }
        while(!s1.empty()){
            int temp=s1.top()+c;
            ListNode *t=new ListNode(temp%10);
            t->next=ans;
            ans=t;
            c=temp/10;
            s1.pop();
        }
        while(!s2.empty()){
            int temp=s2.top()+c;
            ListNode *t=new ListNode(temp%10);
            t->next=ans;
            ans=t;
            c=temp/10;
            s2.pop();
        }
        if(c){
            ListNode *t=new ListNode(1);
            t->next=ans;
            ans=t;
        }
        return ans;
    }
};