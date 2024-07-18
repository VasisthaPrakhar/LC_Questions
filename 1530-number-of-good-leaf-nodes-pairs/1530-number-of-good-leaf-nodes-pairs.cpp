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
    set<TreeNode*> leaf;
    map<TreeNode*, TreeNode*>par;
    void fun(TreeNode* root){
        if(root->left==nullptr && root->right==nullptr){
            leaf.insert(root);
        }
        if(root->left){
            par[root->left]=root;
            fun(root->left);
        }
        if(root->right){
            par[root->right]=root;
            fun(root->right);
        }
    }
    int dfs(TreeNode* root,int d,set<TreeNode*>&vis,TreeNode* node){
        if(d<0 || vis.find(root)!=vis.end()){
            return 0;
        }
        vis.insert(root);
        if(leaf.find(root)!=leaf.end() && root!=node){
            return 1;   
        }
        int res=0;
        if(root->left){
            res+=dfs(root->left,d-1,vis,node);
        }
        if(root->right){
            res+=dfs(root->right,d-1,vis,node);
        }
        if(par.find(root)!=par.end()){
            res+=dfs(par[root],d-1,vis,node);
        }
        return res;
    }
    int countPairs(TreeNode* root, int d) {
        par.clear();
        fun(root);
        int ans=0;
        for(auto x:leaf){
            set<TreeNode*>vis;
            ans+=dfs(x,d,vis,x);
        }
        return ans/2;
    }
};