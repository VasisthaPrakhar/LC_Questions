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
    map<TreeNode*,pair<int,int>>mp;
    pair<int,int> fun(TreeNode* root){
        if(root==nullptr){
            return {0,0};
        }
        pair<int,int>p={0,0},a,b;
        a=fun(root->left);
        b=fun(root->right);
        p.first=a.second+1;
        p.second=b.first+1;
        mp[root]=p;
        return p;
    }
    int longestZigZag(TreeNode* root) {
        if(root==NULL){return 0;}
        mp.clear();
        fun(root);
        int ans=0;
        for(auto x:mp){
            ans=max({ans,x.second.first,x.second.second});
        }
        //cout<<ans;
        //cout<<endl;
        return ans-1;
    }
};