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
    vector<long long int> ans;
    void fun1(string s){
        long long int a=0;
        int j=0;
        for(int i=s.length()-1;i>=0;i--){
            a+=(s[i]-'0')*pow(2,j);
            j++;
        }
        ans.push_back(a);
    }
    void fun(TreeNode* root,string s){
        if(root->left==nullptr && root->right==nullptr){
            fun1(s+to_string(root->val));
            return;
        }
        if(root->left!=nullptr)
        fun(root->left,s+to_string(root->val));
        if(root->right!=nullptr)
        fun(root->right,s+to_string(root->val));
    }
    int sumRootToLeaf(TreeNode* root) {
        string s="";
        fun(root,s);
        long long int res=0;
        for(auto x:ans){
            res+=x;
        }
        return res;
    }
};