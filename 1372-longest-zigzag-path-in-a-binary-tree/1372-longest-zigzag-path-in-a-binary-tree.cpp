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
    // unordered_map<TreeNode*,pair<int,int>>mp;
    pair<int,int> fun(TreeNode* root){
        if(root==nullptr){
            return {0,0};
        }
        pair<int,int>a,b;
        a=fun(root->left);
        b=fun(root->right);
        ans=max({ans,a.second+1,b.first+1});
        return {a.second+1,b.first+1};
    }
    int longestZigZag(TreeNode* root) {
        //mp.clear();
        ans=0;
        fun(root);
        // for(auto x:mp){
        //     ans=max({ans,x.second.first,x.second.second});
        // }
        return ans-1;
    }
};