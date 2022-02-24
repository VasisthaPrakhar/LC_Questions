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
    pair<ListNode*,ListNode*> fun(ListNode* s,ListNode* e,ListNode* prev){
        int pivot=e->val;
        ListNode* i=prev;
        for(auto j=s;j!=e;j=j->next){
            if(j->val<pivot){
                i=i->next;
                swap(i->val,j->val);
            }
        }
        swap(i->next->val,e->val);
        return {i,i->next};
    }
    void ms(ListNode* s,ListNode* e,ListNode* prev){
        if(s==e || s==e->next){
            return;
        }
        auto p=fun(s,e,prev);
        ms(s,p.first,prev);
        ms(p.second->next,e,p.second);
    }
    ListNode* sortList(ListNode* head) {
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        ListNode *ans=head,*temp=head;
        vector<int>a;
        while(head){
            a.push_back(head->val);
            head=head->next;
        }
        sort(a.begin(),a.end());
        for(auto x:a){
            temp->val=x;
            temp=temp->next;
        }
        delete temp;
        // ListNode* ans=head,*st=head;
        // while(head->next!=nullptr){
        //     head=head->next;
        // }
        // ListNode *prev=new ListNode(INT_MIN,st);
        // ms(st,head,prev);
        return ans;
    }
};