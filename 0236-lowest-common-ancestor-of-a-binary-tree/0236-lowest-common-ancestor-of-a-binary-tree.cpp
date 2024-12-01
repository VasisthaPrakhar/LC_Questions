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
        if(root==nullptr){
            return root;
        }
        if(root==p||root==q){
            return root;
        }
        TreeNode* x=lowestCommonAncestor(root->left,p,q);
        TreeNode* y=lowestCommonAncestor(root->right,p,q);
        TreeNode* res;
            if(x && y){
               res=root;
            }else{
                if(x){
                    res=x;
                }else{
                    res=y;
                }
            }
        return res;
    }
};