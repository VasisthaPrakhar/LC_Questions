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
    void fun(TreeNode* root, map<int,int>&m){
        if(root==nullptr){
            return;
        }
        m[root->val]++;
        fun(root->left,m);
        fun(root->right,m);
    }
    vector<int> findMode(TreeNode* root) {
        map<int,int>m;
        fun(root,m);
        int ma=0;
        vector<int>ans;
        for(auto x:m){
            if(ma<x.second){
                ma=x.second;
                ans.clear();
                ans.push_back(x.first);
            }else if(ma==x.second){
                ans.push_back(x.first);
            }
        }
        return ans;
    }
};