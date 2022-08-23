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
    ListNode* rev(ListNode* root){
        ListNode *prev=nullptr;
        while(root){
            auto temp=root->next;
            root->next=prev;
            prev=root;
            root=temp;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        ListNode* slow=head,*fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        slow=rev(slow);
        ListNode* ans=head,*temp;
        auto k=head;
        int f=0;
        while(ans && slow){
            if(f%2==0){
                temp=ans->next;
                if(temp==nullptr){
                    break;
                }
                ans->next=slow;
                slow=slow->next;
                ans=ans->next;
            }else{
                ans->next=temp;
                ans=ans->next;
            }
            f++;
        }
    }
};