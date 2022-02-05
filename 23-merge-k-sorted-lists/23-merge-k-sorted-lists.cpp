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
    struct cmp {
        bool operator()(const ListNode* l, const ListNode* r) {
            return l->val > r->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,cmp>q;
        for(auto x:lists){
            if(x)
            q.push(x);
        }
        if(q.empty()){
            return nullptr;
        }
        ListNode* ans= new ListNode(q.top()->val);
        if(q.top()->next){
            q.push(q.top()->next);
        }
        q.pop();
        ListNode* temp=ans;
        while(!q.empty()){
            temp->next=q.top();
            temp=temp->next;
            q.pop();
            if(temp->next){
                q.push(temp->next);
            }            
        }
        return ans;
    }
};