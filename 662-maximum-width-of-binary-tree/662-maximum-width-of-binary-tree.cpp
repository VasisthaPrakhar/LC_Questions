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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }
        queue<pair<TreeNode*,long long int>>q;
        long long int ans=0;
        q.push({root,0});
        while(!q.empty()){
            long long int s=q.size(),ma=0,mi=0;
            for(int i=0;i<s;i++){
                auto node=q.front();
                q.pop();
                if(i==0)
                    mi=node.second;
                if(i==s-1)
                    ma=node.second;
                if(node.first->left){
                    q.push({node.first->left,2*(node.second-mi)+1});
                }
                if(node.first->right){
                    q.push({node.first->right,2*(node.second-mi)+2});
                }
            }
            ans=max(ans,ma-mi+1);
        }
        return ans;
    }
};