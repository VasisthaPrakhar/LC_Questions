/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        map<ListNode *,int>m;
        while(head != nullptr){
            if(m.count(head)){
                return head;
            }else{
                m[head]=1;
            }
            head=head->next;
        }
        return head;
    }
};