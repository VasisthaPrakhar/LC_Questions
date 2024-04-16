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
    TreeNode* addOneRow(TreeNode* root, int val, int d) {
        if(d==1){
            return new TreeNode(val,root,nullptr);
        }
        queue<TreeNode*>q;
        q.push(root);
        int lvl=1;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto node=q.front();
                q.pop();
                if(lvl==d-1){
                    auto temp=node->left;
                    node->left=new TreeNode(val,temp,nullptr);
                    temp=node->right;
                    node->right=new TreeNode(val,nullptr,temp);
                    q.push(node->left);
                    q.push(node->right);
                }else{
                    if(node->left)
                        q.push(node->left);
                    if(node->right)
                        q.push(node->right);
                }
            }
            lvl++;
        }
        return root;
    }
};