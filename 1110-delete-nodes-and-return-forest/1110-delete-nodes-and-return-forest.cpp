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
    void dfs(TreeNode* root,unordered_set<int>&s,queue<TreeNode*>&q){
        if(root==nullptr){
            return;
        }
        if(root->left && s.find(root->left->val)!=s.end()){
            s.erase(root->left->val);
            if(root->left->left)
                q.push(root->left->left);
            if(root->left->right)
                q.push(root->left->right);
            root->left=nullptr;                
        }
        dfs(root->left,s,q);
        if(root->right && s.find(root->right->val)!=s.end()){
            s.erase(root->right->val);
            if(root->right->left)
                q.push(root->right->left);
            if(root->right->right)
                q.push(root->right->right);
            root->right=nullptr;                
        }
        dfs(root->right,s,q);
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& td) {
        if(!root){
            return {};
        }
        unordered_set<int>s;
        for(auto x:td){
            s.insert(x);
        }
        vector<TreeNode*>ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            if(s.find(node->val)!=s.end()){
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
                continue;
            }
            dfs(node,s,q);
            ans.push_back(node);
        }
        return ans;
    }
};