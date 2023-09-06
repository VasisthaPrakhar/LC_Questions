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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*>a(k);
        if(head==nullptr){
            return a;
        }
        int c=0;
        ListNode* temp=head;
        while(head){
            c++;
            head=head->next;
        }
        int t=c/k,car=c%k,idx=0;
        head=temp;
        while(head){
            int t1=t+(car-->0);
            if(t1>0){
                t1--;
                a[idx++]=head;
                while(t1--){
                    head=head->next;
                }
                auto temp1=head->next;
                head->next=nullptr;
                head=temp1;
            }else
                head=head->next;            
        }
        return a;
    }
};