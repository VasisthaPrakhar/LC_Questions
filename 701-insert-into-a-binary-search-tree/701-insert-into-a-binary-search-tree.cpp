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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==nullptr){
            TreeNode* t=new TreeNode(val);
            return t;
        }
        int f=1;
        TreeNode* head=root;
        while(root && f){
            if(root->val<val){
                if(root->right){
                    root=root->right;
                }else{
                    TreeNode* t=new TreeNode(val);
                    root->right=t;
                    f=0;
                }
            }else{
                if(root->left){
                    root=root->left;
                }else{
                    TreeNode* t=new TreeNode(val);
                    root->left=t;
                    f=0;
                }
            }
        }
        return head;
    }
};