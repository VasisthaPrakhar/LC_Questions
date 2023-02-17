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
        int prev=-100001,ans=100001;
    void in(TreeNode* root){
        if(root==nullptr){
            return;
        }
        in(root->left);
        ans=min(ans,root->val-prev);
        prev=root->val;
        in(root->right);
    }
    int minDiffInBST(TreeNode* root) {
        in(root);
        return ans;
    }
};