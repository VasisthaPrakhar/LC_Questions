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
    TreeNode* fun(vector<int>& pr, vector<int>& in,int s1,int e1,int s2,int e2,unordered_map<int,int>&m){
        if(e1-s1<0){
            return nullptr;
        }
        int k=m[pr[s2]];
        TreeNode* t=new TreeNode(pr[s2],fun(pr,in,s1,k-1,s2+1,s2+k-1-s1,m),fun(pr,in,k+1,e1,s2+k-s1+1,e2,m));
        return t;
    }
    TreeNode* buildTree(vector<int>& pr, vector<int>& in) {
        unordered_map<int,int>m;
        int n=in.size();
        for(int i=0;i<n;i++){
            m[in[i]]=i;
        }
        return fun(pr,in,0,n-1,0,n-1,m);
    }
};
static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();