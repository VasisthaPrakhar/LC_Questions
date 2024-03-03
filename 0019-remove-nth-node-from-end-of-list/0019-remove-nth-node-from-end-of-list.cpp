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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int no=0,i=0;
        ListNode *temp=head;
        while(temp){
            no++;
            temp=temp->next;
        }
        if(no-n==0){
            return head->next;
        }
        temp=head;
        while(temp){
            i++;
            if(i==no-n){
                temp->next=temp->next->next;
                break;
            }
            temp=temp->next;
        }
        return head;
    }
};