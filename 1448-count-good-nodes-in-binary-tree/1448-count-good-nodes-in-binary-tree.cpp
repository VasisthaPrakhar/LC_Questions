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
    int ans=0;
    void fun(TreeNode* root, int ma){
        if(root->val>=ma){
            ans++;
        }
        if(root->left)
            fun(root->left,max(ma,root->left->val));
        if(root->right)
            fun(root->right,max(ma,root->right->val));
    }
    int goodNodes(TreeNode* root) {
        if(!root){
            return 0;
        }
        fun(root,root->val);
        return ans;
    }
};