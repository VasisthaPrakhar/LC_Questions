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
        ListNode *prev,*suf,*temp,*ans=root;
        int i=1,f=0;
        while(i<=right){
            if(left>1 && i+1==left){
                prev=root;
            }
            while(i>=left && i<=right && root){
                if(i==left){
                    temp=root;
                    suf=root;
                    root=root->next;
                }else{
                    ListNode* t=root->next;
                    root->next=suf;
                    suf=root;
                    root=t;
                }
                f=1;
                i++;
            }
            if(f){
                temp->next=root;
                if(left>1)
                    prev->next=suf;
                else
                    ans=suf;                    
            }
            i++;
            if(root)
            root=root->next;
        }
        return ans;
    }
};