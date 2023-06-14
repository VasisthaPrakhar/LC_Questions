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
    int prev=INT_MAX,ans=INT_MAX;
    void in(TreeNode* root){
        if(root==nullptr){
            return;
        }
        in(root->left);
        ans=min(ans,abs(root->val-prev));
        prev=root->val;
        in(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }
        in(root);
        return ans;
    }
};