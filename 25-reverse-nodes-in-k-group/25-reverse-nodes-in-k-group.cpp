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
    pair<ListNode*,ListNode*> reverse(ListNode* root){
        ListNode *prev=nullptr,*ans=root;
        while(root){
            auto temp=root->next;
            root->next=prev;
            prev=root;
            root=temp;
        }
        return {prev,ans};
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* root=head,*ans=nullptr,*prev=nullptr,*temp1=nullptr;
        int n=0,f=1;
        while(root){
            n++;
            auto temp=root->next;
            if(n%k==0){
                temp1=root->next;
                if(f){
                    root->next=nullptr;
                    auto t=reverse(head);
                    ans=t.first;
                    prev=t.second;
                    f--;
                }else{
                    root->next=nullptr;
                    auto t=reverse(head);
                    prev->next=t.first;
                    prev=t.second;
                }
                head=temp;
            }
            root=temp;
        }
        prev->next=temp1;
        return ans;
    }
};