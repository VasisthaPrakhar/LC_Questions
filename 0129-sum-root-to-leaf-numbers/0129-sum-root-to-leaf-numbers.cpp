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
    typedef long long int ll;
    void fun(TreeNode* root,string s,ll &k){
        if(root==nullptr){
            return;
        }
        s.push_back(root->val+'0');
        if(root->left==nullptr && root->right==nullptr){
            k+=stoll(s);
            s.pop_back();
            return;
        }
        fun(root->left,s,k);
        fun(root->right,s,k);
        s.pop_back();
    }
    int sumNumbers(TreeNode* root) {
        ll ans=0;
        fun(root,"",ans);
        return ans;
    }
};