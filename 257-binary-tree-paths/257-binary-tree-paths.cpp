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
    void fun(TreeNode* root,string res,vector<string>&ans){
        if(!root->left && !root->right){
            ans.push_back(res+to_string(root->val));
            return;
        }
        if(root->left){
            fun(root->left,res+to_string(root->val)+"->",ans);
        }
        if(root->right){
            fun(root->right,res+to_string(root->val)+"->",ans);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        fun(root,"",ans);
        return ans;
    }
};