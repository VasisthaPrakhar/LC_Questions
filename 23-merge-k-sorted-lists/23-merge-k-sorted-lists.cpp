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
        vector<ListNode*>v;
        for(auto x:lists){
            while(x){
                ListNode* temp=new ListNode(x->val);
                v.push_back(temp);
                x=x->next;
            }
        }
        if(v.size()==0){
            return nullptr;
        }
        sort(v.begin(),v.end(),[](const ListNode* l, const ListNode* r)->bool{
            return l->val < r->val;
        });
        ListNode *prev=nullptr,*ans=nullptr;
        int f=1;
        for(auto x:v){
            if(f){
                ans=x;
                prev=x;
                f--;
            }else{
                prev->next=x;
                prev=prev->next;
            }
        }
        prev->next=nullptr;
        return ans;
    }
};