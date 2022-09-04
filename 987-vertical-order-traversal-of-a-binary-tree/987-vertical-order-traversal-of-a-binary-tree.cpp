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
static const auto Initialize = []{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>res;
        if(root==nullptr){
            return res;
        }
        map<int,map<int,multiset<int>>>m;
        queue<pair<TreeNode*,pair<int,int>>>q;
        
        q.push({root,{0,0}});
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            int x=node.second.second;
            int y=node.second.first;
            m[x][y].insert(node.first->val);
            if(node.first->left){
                q.push({node.first->left,{y+1,x-1}});
            }
            if(node.first->right){
                q.push({node.first->right,{y+1,x+1}});
            }
        }
        for(auto x:m){
            vector<int>ans;
            for(auto y:x.second){
                ans.insert(ans.end(),y.second.begin(),y.second.end());
            }
            res.push_back(ans);
        }
        return res;
    }
};