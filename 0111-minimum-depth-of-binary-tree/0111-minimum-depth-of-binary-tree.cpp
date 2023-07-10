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
    int minDepth(TreeNode* root) {
        if(!root){return 0;}
        if(root->left==nullptr && root->right==nullptr){return 1;}
        int a=5000,b=5000;
        if(root->left){
            a=minDepth(root->left);
        }
        if(root->right){
            b=minDepth(root->right);
        }
        return 1+min(a,b);
    }
};