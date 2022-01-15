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
    int fun(TreeNode* root, int &ma){
        if(root==nullptr){return 0;}
        int l=fun(root->left,ma);
        int r=fun(root->right,ma);
        l=l>0?l:0;
        r=r>0?r:0;
        ma=max(ma,root->val+l+r);
        return root->val+max(l,r);
    }
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        int k=fun(root,ans);
        return ans;
    }
};