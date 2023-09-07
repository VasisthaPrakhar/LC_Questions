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
    ListNode* reverse(ListNode* head,int n){
        ListNode* prev=nullptr,*temp=nullptr,*curr=head;
        while(head && n){
            temp=head->next;
            head->next=prev;
            prev=head;
            head=temp;
            n--;
        }
        curr->next=temp;
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* prev=nullptr,*ans=head;
        int n=1;
        while(head){
            if(n==left){
                auto res=reverse(head,right-left+1);
                if(prev==nullptr){
                    return res;
                }
                prev->next=res;
                break;
            }
            prev=head;
            n++;
            head=head->next;
        }
        
      return ans;  
    }
};