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
    long long int rh=0;
    void fun(TreeNode* root){
        if(!root){
            return;
        }
        fun(root->right);
        root->val+=rh;
        rh=root->val;
        fun(root->left);
    }
    TreeNode* bstToGst(TreeNode* root) {
        fun(root);
        return root;
    }
};