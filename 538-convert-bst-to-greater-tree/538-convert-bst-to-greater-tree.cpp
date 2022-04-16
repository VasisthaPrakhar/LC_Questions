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
    void fun(TreeNode* root,int &sum){
        if(root==nullptr){
            return;
        }
        fun(root->right,sum);
        root->val+=sum;
        sum=root->val;
        fun(root->left,sum);
    }
    TreeNode* convertBST(TreeNode* root) {
        int sum=0;
        fun(root,sum);
        return root;
    }
};