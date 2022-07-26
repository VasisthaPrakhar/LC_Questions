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
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int>s(nums.begin(),nums.end());
        int ans=0;
        while(head){
            int f=0;
            if(s.find(head->val)!=s.end()){
                while(head && s.find(head->val)!=s.end()){
                    head=head->next;
                }
                f=1;
                ans++;
            }
            if(!f){
                head=head->next;
            }
        }
        return ans;
    }
};