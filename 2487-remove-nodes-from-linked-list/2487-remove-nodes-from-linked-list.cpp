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
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*>s;
        while(head){
            while(s.size()>0 && s.top()->val<head->val){
                s.pop();
            }
            s.push(head);
            head=head->next;
        }
        ListNode* prev=NULL;
        while(!s.empty()){
            s.top()->next=prev;
            prev=s.top();
            s.pop();
        }
        return prev;
    }
};