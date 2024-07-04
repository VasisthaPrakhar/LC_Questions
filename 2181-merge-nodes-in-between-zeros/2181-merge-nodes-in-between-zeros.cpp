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
    ListNode* mergeNodes(ListNode* head) {
        if(head==nullptr){
            return head;
        }
        ListNode* ans=NULL,*res;
        int s=0;
        while(head){
            if(head->val==0){
                if(s!=0){
                    ListNode* temp=new ListNode(s);
                    if(ans==NULL){
                        ans=temp;
                        res=ans;
                    }else{
                        res->next=temp;
                        res=res->next;
                    }
                }
                s=0;
            }else{
                s+=head->val;
            }
            head=head->next;
        }
        return ans;
    }
};