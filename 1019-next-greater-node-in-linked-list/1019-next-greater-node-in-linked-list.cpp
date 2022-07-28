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
    vector<int> nextLargerNodes(ListNode* head) {
        int n=0;
        ListNode* t=head;
        while(t){
            n++;
            t=t->next;
        }
        stack<pair<int,int>>s;
        vector<int>ans(n,0);
        int i=0;
        while(head){
            int k=head->val;
            while(!s.empty() && k>s.top().first){
                ans[s.top().second]=k;
                s.pop();
            }
            s.push({k,i});
            i++;
            head=head->next;
        }
        return ans;
    }
};