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
    bool isPalindrome(ListNode* head) {
        if(head->next==nullptr){
            return true;
        }
        vector<int>a;
        int n=0;
        while(head){
            a.push_back(head->val);
            n++;
            head=head->next;
        }
        int j=n-1,i=0;
        while(i<=j){
            if(a[i++]!=a[j--]){
                return false;
            }
        }
        return true;
    }
};