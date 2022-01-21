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
    TreeNode* fun(vector<int>& in, vector<int>& po,int s1,int e1,int e2,unordered_map<int,int>&m){
        if(e1-s1<0){
            return nullptr;
        }
        int k=m[po[e2]];
        TreeNode* t= new TreeNode(po[e2],fun(in,po,s1,k-1,e2-(e1-k)-1,m),fun(in,po,k+1,e1,e2-1,m));
        return t;
    }
    TreeNode* buildTree(vector<int>& in, vector<int>& po) {
        int n=in.size();
        unordered_map<int,int>m;
        for(int i=0;i<n;i++){
            m[in[i]]=i;
        }
        return fun(in,po,0,n-1,n-1,m);
    }
};