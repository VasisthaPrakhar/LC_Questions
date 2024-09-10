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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* ans=head;
        while(head){
            int a=head->val,b=0;
            ListNode* temp=NULL;
            if(head->next){
                b=head->next->val;
                temp=head->next;
                int k=__gcd(a,b);
                ListNode* z=new ListNode(k);
                head->next=z;
                z->next=temp;
                head=temp;
            }else{
                break;
            }
        }
        return ans;
    }
};