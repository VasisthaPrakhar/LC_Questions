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
        auto front=head;
        while(front->next && front->next->next){
            head=head->next;
            front=front->next->next;
            if(head==front){
                return true;
            }
        }
        return false;
    }
};