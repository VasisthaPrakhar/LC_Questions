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
    ListNode* fun(ListNode* head,int k){
        ListNode* prev=NULL,*temp=nullptr,*t=head;
        while(head && k--){
            temp=head->next;
            head->next=prev;
            prev=head;
            head=temp;
        }
        t->next=head;
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* ans=NULL,*prev=NULL,*t=head;
        int c=0;
        while(t){
            c++;
            t=t->next;
        }
        int z=c/k;
        while(head && z--){
            if(ans==NULL){
                auto temp=head;
                ans=fun(head,k);
                prev=temp;
            }else{
                auto temp=head;
                prev->next=fun(head,k);
                prev=temp;
            }
            head=head->next;
        }
        return ans;
    }
};