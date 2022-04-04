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
    ListNode* swapNodes(ListNode* head, int k) {
        if(head->next==nullptr){
            return head;
        }
        ListNode*ans=head,*one,*temp=nullptr;
        while(head){
            k--;
            if(k==0){
                one=head;
            }
            if(k==-1){
                temp=ans;
            }
            if(temp){
                temp=temp->next;
            }
            head=head->next;
        }
        if(temp==nullptr && k==0){
            temp=ans;
        }
        if(temp && one)
        swap(temp->val,one->val);
        return ans;
    }
};