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
    int amountOfTime(TreeNode* root, int start) {
        queue<TreeNode*>q;
        q.push(root);
        TreeNode* temp=nullptr;
        map<TreeNode*,TreeNode*>par;
        par[root]=nullptr;
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            if(node->val==start){
                temp=node;
            }
            if(node->left){
                par[node->left]=node;
                q.push(node->left);
            }
            if(node->right){
                par[node->right]=node;
                q.push(node->right);
            }
        }
        q.push(temp);
        int ans=-1;
        set<TreeNode*>vis;
        vis.insert(temp);
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto node=q.front();
                q.pop();
                if(par[node] && !vis.count(par[node])){
                    vis.insert(par[node]);
                    q.push(par[node]);
                }
                if(node->left && !vis.count(node->left)){
                    vis.insert(node->left);
                    q.push(node->left);
                }
                if(node->right && !vis.count(node->right)){
                    vis.insert(node->right);
                    q.push(node->right);
                }
            }
            ans++;
        }
        return ans;
    }
};