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
    int ans;
    pair<int,int> fun(TreeNode* root){
        if(root==nullptr){
            return {0,0};
        }
        pair<int,int> l,r;
        l=fun(root->left);
        r=fun(root->right);
        ans=max({ans,l.second+1,r.first+1});
        return {l.second+1,r.first+1};
    }
    int longestZigZag(TreeNode* root) {
        ans=0;
        auto x=fun(root);
        //if(ans==0)return ans;
        return ans-1;
        // cout<<x.first<<" "<<x.second<<" "<<ans<<endl;
        // return 0;
    }
};