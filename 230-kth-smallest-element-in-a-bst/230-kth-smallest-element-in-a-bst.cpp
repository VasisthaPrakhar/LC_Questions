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
    void fun(TreeNode* root,vector<int>&a){
        if(root==nullptr){
            return;
        }
        fun(root->left,a);
        a.push_back(root->val);
        fun(root->right,a);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int>f;
        fun(root,f);
        return f[k-1];
    }
};