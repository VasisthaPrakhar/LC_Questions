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
    bool fun(TreeNode* root,TreeNode* root1){
        if(root==nullptr && root1==nullptr){
            return true;
        }
        if(root==nullptr && root1!=nullptr){
            return false;
        }
        if(root!=nullptr && root1==nullptr){
            return false;
        }
        if(root->val!=root1->val){
            return false;
        }
        return fun(root->left,root1->left) && fun(root->right,root1->right);
        
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==nullptr){
            return false;
        }
        if(root->val==subRoot->val){
            if(fun(root,subRoot)){
                return true;
            }
        }
        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
};