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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
     TreeNode* fun(ListNode* s,ListNode* e){
        if(e->next==s){
            return nullptr;
        }
        if(s==e){
            return new TreeNode(s->val);
        }
        ListNode* mid=s,*f=s->next->next;
        while(f && f!=e && f!=e->next){
            mid=mid->next;
            f=f->next->next;
        }
         //cout<<s->val<<" ";
        TreeNode* t=new TreeNode(mid->next->val);
        t->left=fun(s,mid);
        t->right=fun(mid->next->next,e);
        return t;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==nullptr){
            return nullptr;
        }
        ListNode* temp=head;
        while(head->next!=nullptr){
            head=head->next;
        }
        return fun(temp,head);
    }
};