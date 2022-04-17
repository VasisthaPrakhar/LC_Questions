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
    TreeNode* head=new TreeNode(-1);
    TreeNode* ans=head;
    void fun(TreeNode* root){
        if(root==nullptr){
            return;
        }
        fun(root->left);
        TreeNode* t=new TreeNode(root->val);
        head->right=t;
        head=head->right;
        fun(root->right);
    }
    TreeNode* increasingBST(TreeNode* root) {
        fun(root);
        return ans->right;
    }
};