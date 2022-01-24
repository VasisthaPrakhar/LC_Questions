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
private:
    TreeNode *first,*last,*mid,*prev;
public:
    void fun(TreeNode* root){
        if(root==nullptr){
            return;
        }
        fun(root->left);
        if(prev!=nullptr && root->val<prev->val){
            if(first==nullptr){
                first=prev;
                mid=root;
            }else{
                last=root;
            }
        }
        prev=root;
        fun(root->right);
    }
    void recoverTree(TreeNode* root) {
        first=nullptr,last=nullptr,mid=nullptr;
        prev=new TreeNode(INT_MIN);
        fun(root);
        if(first && last){
            swap(first->val,last->val);
        }else{
            swap(first->val,mid->val);
        }
    }
};