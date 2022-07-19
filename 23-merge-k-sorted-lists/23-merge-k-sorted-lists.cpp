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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*>>v;
        for(auto x:lists){
            while(x){
                ListNode* temp=new ListNode(x->val);
                v.push({x->val,temp});
                x=x->next;
            }
        }
        if(v.size()==0){
            return nullptr;
        }
        ListNode *ans=nullptr;
        while(!v.empty()){
            ListNode *temp=v.top().second;
            temp->next=ans;
            ans=temp;
            v.pop();
        }
        return ans;
    }
};