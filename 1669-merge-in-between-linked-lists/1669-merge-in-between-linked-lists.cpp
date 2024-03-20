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
    ListNode* mergeInBetween(ListNode* l1, int a, int b, ListNode* l2) {
        ListNode* ans=l1,*k;
        int n=a;
        while(n>1){l1=l1->next; n--;}
        k=l1->next;
        l1->next=l2;
        while(l1->next!=NULL){
            l1=l1->next;
        }
        int z=b-a+1;
        while(k && z){
            //if(k){cout<<k->val<<" ";}
            k=k->next;
            z--;
        }
        l1->next=k;
        return ans;
    }
};