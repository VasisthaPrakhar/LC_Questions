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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>a;
        int i=0;
        ListNode *prev=NULL;
        while(head){
            if(prev!=NULL && head->next!=NULL){
                if((prev->val<head->val && head->val>head->next->val)||(prev->val>head->val && head->val<head->next->val)){
                    a.push_back(i);
                }
            }
            i++;
            prev=head;
            head=head->next;
        }
        if(a.size()<2){
            return {-1,-1};
        }
        int n=a.size(),mi=INT_MAX;
        for(int i=0;i<n-1;i++){
            mi=min(a[i+1]-a[i],mi);
        }
        return {mi,a[n-1]-a[0]};
    }
};