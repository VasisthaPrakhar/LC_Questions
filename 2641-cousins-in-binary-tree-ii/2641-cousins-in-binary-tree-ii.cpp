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
    TreeNode* replaceValueInTree(TreeNode* root) {
        TreeNode* t=new TreeNode(-1);
        queue<pair<TreeNode*,TreeNode*>>q;
        q.push({root,t});
        unordered_map<TreeNode*,int>m;
        m[t]=root->val;
        unordered_map<int,int>mp;
        int lvl=0;
        while(!q.empty()){
            int sz=q.size();
            int ss=0;
            while(sz--){
                auto node=q.front().first;
                auto par=q.front().second;
                q.pop();
                int sum=0;
                ss+=node->val;
                if(node->left){
                    sum+=node->left->val;
                    q.push({node->left,node});
                }
                if(node->right){
                    sum+=node->right->val;
                    q.push({node->right,node});
                }
                m[node]=sum;
            }
            mp[lvl]=ss;
            lvl++;
        }
        // for(auto x:m){
        //     cout<<x.first->val<<" "<<x.second<<endl;
        // }
        lvl=0;
        q.push({root,t});
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto node=q.front().first;
                auto par=q.front().second;
                q.pop();
                if(node->left){
                    q.push({node->left,node});
                }
                if(node->right){
                    q.push({node->right,node});
                }
                node->val=mp[lvl]-m[par];
            }
            lvl++;
        }
        return root;
    }
};