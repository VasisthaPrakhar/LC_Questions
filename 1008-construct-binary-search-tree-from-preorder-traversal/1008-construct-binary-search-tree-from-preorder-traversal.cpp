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
    TreeNode* fun(vector<int>& in, vector<int>& pr, int s1, int e1, int s2, unordered_map<int,int>m){
        if(s1>e1){
            return nullptr;
        }
        int k=m[pr[s2]];
        TreeNode *t = new TreeNode(pr[s2],fun(in,pr,s1,k-1,s2+1,m),fun(in,pr,k+1,e1,s2+k-s1+1,m));
        return t;
    }
    TreeNode* bstFromPreorder(vector<int>& pr) {
        vector<int>in=pr;
        sort(in.begin(),in.end());
        unordered_map<int,int>m;
        int n=in.size();
        for(int i=0;i<n;i++){
            m[in[i]]=i;
        }
        return fun(in,pr,0,n-1,0,m);
    }
};