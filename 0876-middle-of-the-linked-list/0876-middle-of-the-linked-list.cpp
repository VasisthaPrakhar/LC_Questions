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
    ListNode* middleNode(ListNode* head) {
        ListNode *temp=head,*ans=head;
        int c=0;
        while(temp!=NULL){
            c++;
            temp=temp->next;
        }
        delete temp;
        c=c/2;
        while(c--){
            ans=ans->next;
        }
        return ans;
    }
};