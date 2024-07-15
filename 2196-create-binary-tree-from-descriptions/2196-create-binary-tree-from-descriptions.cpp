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
    TreeNode* createBinaryTree(vector<vector<int>>& desc) {
       int n=desc.size();
        unordered_map<int,TreeNode*>m;
        unordered_map<int,int>m1;
        int root;
        for(int i=0;i<n;i++){
            if(!m1.count(desc[i][0])){
                m1[desc[i][0]]=-1;
            }
            m1[desc[i][1]]=desc[i][0];
        }
        for(auto x:m1){
            if(x.second==-1){
                root=x.first;
            }
            TreeNode* t=new TreeNode(x.first);
            m[x.first]=t;
        }
        for(int i=0;i<n;i++){
            auto x=m[desc[i][0]],y=m[desc[i][1]];
            if(desc[i][2]){
                x->left=y;
            }else{
                x->right=y;
            }
        }
        return m[root];
    }
};