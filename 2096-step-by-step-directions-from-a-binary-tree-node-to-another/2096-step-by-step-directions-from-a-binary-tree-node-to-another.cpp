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
    TreeNode* t=NULL;
    void fun(TreeNode* root, unordered_map<int,TreeNode*>&par, int s){
        if(root->val==s){
            t=root;
        }
        if(root->left){
            par[root->left->val]=root;
            fun(root->left,par,s);
        }
        if(root->right){
            par[root->right->val]=root;
            fun(root->right,par,s);
        }
    }
    void fun1(TreeNode* root, unordered_map<int,TreeNode*>&par,string &s, string &ans,int d,unordered_set<int>&vis){
        if(root==NULL){
            return;
        }
        vis.insert(root->val);
        if(root->val==d){
            ans=s;
            return;
        }
        if(ans.length()>0){
            return;
        }
        if(root->left && vis.find(root->left->val)==vis.end()){
            s.push_back('L');
            fun1(root->left,par,s,ans,d,vis);
            s.pop_back();
        }
        if(ans.length()>0){
            return;
        }
        if(root->right && vis.find(root->right->val)==vis.end()){
            s.push_back('R');
            fun1(root->right,par,s,ans,d,vis);
            s.pop_back();
        }
        if(ans.length()>0){
            return;
        }
        if(par.find(root->val)!=par.end() && vis.find(par[root->val]->val)==vis.end()){
            s.push_back('U');
            fun1(par[root->val],par,s,ans,d,vis);
            s.pop_back();
        }
    }
    string getDirections(TreeNode* root, int s, int d) {
        unordered_map<int,TreeNode*>par;
        fun(root,par,s);
        string ans="",st="";
        unordered_set<int>vis;
        fun1(t,par,st,ans,d,vis);
        return ans;
    }
};