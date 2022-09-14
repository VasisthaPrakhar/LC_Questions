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
    bool check(vector<int>&m){
        int cnt=0;
        for(auto x:m){
            if(x%2){
                cnt++;
            }
        }
        if(cnt<=1){
            return true;
        }
        return false;
    }
    void fun(TreeNode* root, vector<int>&m){
        if(root==nullptr){
            if(check(m)){
                ans++;
            }
            return;
        }
        m[root->val]++;
        if(!root->left && !root->right){
            fun(root->left,m);
        }else if(!root->left){
            fun(root->right,m);
        }else if(!root->right){
            fun(root->left,m);
        }else{
            fun(root->left,m);
            fun(root->right,m);
        }
        m[root->val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int>m(10,0);
        fun(root,m);
        return ans;
    }
};