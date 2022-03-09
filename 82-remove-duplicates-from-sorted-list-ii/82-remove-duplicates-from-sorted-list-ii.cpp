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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* ans=new ListNode(-101);
        map<int,int>s;
        while(head){
            s[head->val]++;
            head=head->next;
        }
        auto res=ans;
        for(auto x:s){
            if(x.second==1){
            ListNode* temp=new ListNode(x.first);
            ans->next=temp;
            ans=ans->next;}
        }
        return res->next;
    }
};