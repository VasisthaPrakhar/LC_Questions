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
    ListNode* reverseBetween(ListNode* root, int left, int right) {
        if(root->next==nullptr || left==right){
            return root;
        }
        ListNode *ans=root;
        stack<int>s;
        int i=1;
        while(root){
            if(i>=left && i<=right){
                s.push(root->val);
            }
            i++;
            root=root->next;
        }
        root=ans;
        i=1;
        while(root){
            if(i>=left && i<=right){
                root->val=s.top();
                s.pop();
            }
            i++;
            root=root->next;
        }
        return ans;
    }
};