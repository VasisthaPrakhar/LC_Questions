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
    ListNode* oddEvenList(ListNode* head) {
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        ListNode* eve=head->next;
        ListNode* odd=head;
        ListNode* temp=eve;
        
        while(odd->next && eve->next){
            odd->next=eve->next;
            eve->next=odd->next->next;
            odd=odd->next;
            eve=eve->next;
        }
        odd->next=temp;
        return head;
    }
};