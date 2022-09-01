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
        if(root->left){
            int l=root->left->val;
            int k = ma>l?ma:l;
            fun(root->left,k);
        }
        if(root->right){
            int l=root->right->val;
            int k = ma>l?ma:l;
            fun(root->right,k);
        }
    }
    int goodNodes(TreeNode* root) {
        if(!root){
            return 0;
        }
        fun(root,root->val);
        return ans;
    }
};