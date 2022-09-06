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
    int fun(TreeNode* root){
        if(root==nullptr){
            return 0;
        }
        int a=fun(root->left),b=fun(root->right);
        if(a==1){
            root->left=nullptr;
        }
        if(b==1){
            root->right=nullptr;
        }
        if(root->val==1){
            return 2;
        }else{
            if(a==2 || b==2){
                return 2;
            }
            return 1;
        }
    }
    TreeNode* pruneTree(TreeNode* root) {
        int a=fun(root);
        if(a==1){
            return nullptr;
        }
        return root;
    }
};