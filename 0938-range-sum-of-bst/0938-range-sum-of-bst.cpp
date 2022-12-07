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
    void fun(vector<int>&a,TreeNode* root){
        if(root==nullptr){
            return;
        }
        fun(a,root->left);
        a.push_back(root->val);
        fun(a,root->right);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        vector<int>a;
        fun(a,root);
        int sum=0;
        for(auto x:a){
            if(x>=low && x<=high){
                sum+=x;
            }
        }
        return sum;
    }
};