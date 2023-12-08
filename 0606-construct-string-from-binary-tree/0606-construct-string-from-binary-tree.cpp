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
    string tree2str(TreeNode* root) {
         if(root==nullptr){
            return "";
        }
        string r="",l="";
        if(root->left!=nullptr || root->right!=nullptr)
            l="("+tree2str(root->left)+")";
        if(root->right!=nullptr)
            r="("+tree2str(root->right)+")";
        return to_string(root->val)+l+r;
    }
};