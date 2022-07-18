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
    int ans=0;
    //unordered_set<TreeNode*>vis;
    int dfs(TreeNode* root,TreeNode* node){
        if(root==nullptr){
            return 0;
        }
        //vis.insert(root);
        int l=0,r=0;
        if(root->left && root->left->val==root->val){
            l=1+dfs(root->left,node);
        }
        if(root->right && root->right->val==root->val){
            r=1+dfs(root->right,node);
        }
        if(root==node){
            return l+r;
        }
        return max(l,r);
    }
    void fun(TreeNode* root){
        if(root==nullptr){
            return;
        }
        //if(!vis.count(root))
            ans=max(ans,dfs(root,root));
        fun(root->left);
        fun(root->right);
    }
    int longestUnivaluePath(TreeNode* root) {
        fun(root);
        return ans;
    }
};