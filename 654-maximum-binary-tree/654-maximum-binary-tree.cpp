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
    pair<int,int> fun(vector<int>&a,int st,int end){
        int ele=-1,pos=-1;
        for(int i=st;i<=end;i++){
            if(a[i]>ele){
                ele=a[i];
                pos=i;
            }
        }
        return {pos,ele};
    }
    TreeNode* fun1(vector<int>&a,int st,int end,int n){
        if(st>end){
            return nullptr;
        }
        if(end==st){
            return new TreeNode(a[st]);
        }
        auto x=fun(a,st,end);
        TreeNode* root=new TreeNode(x.second);
        if(x.first>0)
        root->left=fun1(a,st,x.first-1,n);
        if(x.first+1<n)
        root->right=fun1(a,x.first+1,end,n);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n=nums.size();
        return fun1(nums,0,n-1,n);
    }
};