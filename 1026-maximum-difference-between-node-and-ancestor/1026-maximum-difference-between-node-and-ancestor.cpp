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
    int ans;
    pair<int,int> fun(TreeNode* root){
        if(root->left==nullptr && root->right==nullptr){
            return {root->val,root->val};
        }else{
            pair<int,int>a,b;
            a={INT_MAX,INT_MIN};
            b={INT_MAX,INT_MIN};
            if(root->left){
                a=fun(root->left);
            }
            if(root->right){
                b=fun(root->right);
            }
            int mi=min(a.first,b.first);
            int ma=max(a.second,b.second);
            ans=max({ans,abs(mi-root->val),abs(ma-root->val)});
            return {min({a.first,b.first,root->val}),max({a.second,b.second,root->val})};
        }
        
    }
    int maxAncestorDiff(TreeNode* root) {
        ans=0;
        auto f=fun(root);
        return ans;
    }
};