/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* ans;
    void fun(TreeNode* root, TreeNode* root1, TreeNode* t){
        if(root==nullptr){
            return;
        }
        fun(root->left,root1->left,t);
        if(root==t){
            ans=root1;
        }
        fun(root->right,root1->right,t);
    }
    TreeNode* getTargetCopy(TreeNode* o, TreeNode* c, TreeNode* t){
        fun(o,c,t);
        return ans;
    }
};