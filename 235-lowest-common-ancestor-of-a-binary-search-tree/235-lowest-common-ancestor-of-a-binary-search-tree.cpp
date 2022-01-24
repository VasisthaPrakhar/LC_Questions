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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(root){
            int k=root->val;
            if(k>p->val && k>q->val){
                root=root->left;
            }else if(k<p->val && k<q->val){
                root=root->right;
            }else{
                break;
            }
        }
        return root;
    }
};