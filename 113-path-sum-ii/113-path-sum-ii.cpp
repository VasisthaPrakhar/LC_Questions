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
    vector<vector<int>>ans;
    void fun(TreeNode* root,int sum,vector<int>&res,int t){
        if(root==nullptr){
            return;
        }
        if(root->left==nullptr && root->right==nullptr){
            int k=sum+root->val;
            res.push_back(root->val);
            if(t==k){
                ans.push_back(res);
            }
            res.pop_back();
            return;
        }
        res.push_back(root->val);
        fun(root->left,sum+root->val,res,t);
        fun(root->right,sum+root->val,res,t);
        res.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int t) {
        vector<int>res;
        fun(root,0,res,t);
        return ans;
    }
};