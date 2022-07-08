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
    ListNode* swapPairs(ListNode* head) {
        if(head==nullptr){
            return head;
        }
        ListNode* ans,*prev=nullptr;
        int f=1;
        while(head){
            if(head->next!=nullptr){
                auto temp=head->next;
                head->next=temp->next;
                temp->next=head;
                if(f){
                    ans=temp;
                    f--;
                }else{
                    prev->next=temp;
                }
            }
            prev=head;
            head=head->next;
        }
        return ans;
    }
};