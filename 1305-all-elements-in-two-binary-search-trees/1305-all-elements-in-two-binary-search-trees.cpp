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
    void fun(TreeNode* root,vector<int>&a){
        if(root==nullptr){
            return;
        }
        fun(root->left,a);
        a.push_back(root->val);
        fun(root->right,a);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>a,b;
        fun(root1,a);
        fun(root2,b);
        int n=a.size(),m=b.size();
        int i=0,j=0,k=0;
        vector<int>ans(n+m);
        while(i<n && j<m){
            if(a[i]<=b[j]){
                ans[k++]=a[i++];
            }else{
                ans[k++]=b[j++];
            }
        }
        while(i<n){
            ans[k++]=a[i++];
        }
        while(j<m){
            ans[k++]=b[j++];
        }
        return ans;
    }
};