/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head){
            return false;
        }
        auto front=head->next;
        while(front!=nullptr){
            if(head==front){
                return true;
            }
            head=head->next;
            if(front->next)
                front=front->next->next;
            else
                front=front->next;
        }
        return false;
    }
};