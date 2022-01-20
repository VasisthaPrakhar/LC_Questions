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
        int l=0;
        while(root){
            l++;
            root=root->left;
        }
        return l;
    }
    int fun1(TreeNode* root){
        int l=0;
        while(root){
            l++;
            root=root->right;
        }
        return l;
    }
    int countNodes(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }
        int l=fun(root);
        int r=fun1(root);
        if(l==r){
            return (1<<l)-1;
        }
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};