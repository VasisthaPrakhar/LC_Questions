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
    int fun(TreeNode* root){
        if(root==nullptr){
            return -1;
        }
        int l=fun(root->left);
        int r=fun(root->right);
        if(l==0 || r==0){
            ans++;
            return 1;
        }
        if(l==1 || r==1){
            return -1;
        }else{
            return 0;
        }
        
    }
    int minCameraCover(TreeNode* root) {
        if(fun(root)==0){
            ans++;
        }
        return ans;
    }
};