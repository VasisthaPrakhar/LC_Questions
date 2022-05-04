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
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr){
            return nullptr;
        }
        ListNode* ans=head,*res=head;
        vector<int>a;
        while(head){
            a.push_back(head->val);
            head=head->next;
        }
        reverse(a.begin(),a.end());
        int i=0;
        while(res){
            res->val=a[i++];
            res=res->next;
        }
        return ans;
    }
};