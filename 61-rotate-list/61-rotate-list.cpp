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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr || k==0){
            return head;
        }
        ListNode *ans=head,*res;
        int c=0;
        while(head){
            c++;
            head=head->next;
        }
        if(c==1){
            return ans;
        }
        int t=c;
        c=c-k%c;
        if(c==0 || c-t==0){
            return ans;
        }
        head=ans;
        while(head->next){
            c--;
            if(c==0){
                auto temp=head->next;
                head->next=nullptr;
                head=temp;
                res=head;
            }else{
                head=head->next;
            }
        }
        head->next=ans;
        return res;
    }
};