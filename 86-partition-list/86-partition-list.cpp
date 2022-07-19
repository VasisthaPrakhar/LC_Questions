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
    ListNode* partition(ListNode* head, int x) {
        ListNode* ans=new ListNode(-1),*root=head,*res=ans;
        while(head){
            if(head->val<x){
                ans->next=new ListNode(head->val);
                ans=ans->next;
            }
            head=head->next;
        }
        while(root){
            if(root->val>=x){
                ans->next=new ListNode(root->val);
                ans=ans->next;
            }
            root=root->next;
        }
        return res->next;
    }
};