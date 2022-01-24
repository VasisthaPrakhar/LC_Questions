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
    bool fun(TreeNode* root,long long int u,long long int v){
        if(root==nullptr){
            return true;
        }
        if(root->val<=u || root->val>=v){
            return false;
        }
        return fun(root->left,u,root->val)&&fun(root->right,root->val,v);
    }
    bool isValidBST(TreeNode* root) {
        if(!root->left && !root->right){
            return true;
        }
        return fun(root,LLONG_MIN, LLONG_MAX);   
    }
};