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
    TreeNode* fun(vector<int>& nums,int s,int e){
        if(s>e){
            return nullptr;
        }
        if(s==e){
            TreeNode* t=new TreeNode(nums[s]);
            return t;
        }
        int mid=(s+e)/2;
        TreeNode* t=new TreeNode(nums[mid]);
        t->left=fun(nums,s,mid-1);
        t->right=fun(nums,mid+1,e);
        return t;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n=nums.size();
        if(n==0){
            return nullptr;
        }
        return fun(nums,0,n-1);
    }
};