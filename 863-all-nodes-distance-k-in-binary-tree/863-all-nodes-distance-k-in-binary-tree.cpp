/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*,TreeNode*>m;
        queue<TreeNode*>q;
        q.push(root);
        m[root]=nullptr;
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            if(node->left){
                q.push(node->left);
                m[node->left]=node;
            }
            if(node->right){
                q.push(node->right);
                m[node->right]=node;
            }
        }
        q.push(target);
        map<TreeNode*,bool>vis;
        vis[target]=true;
        vector<int>ans;
        int res=-1;
        while(!q.empty()){
            int s=q.size();
            res++;
            for(int i=0;i<s;i++){
                auto node=q.front();
                q.pop();
                if(res==k){
                    ans.push_back(node->val);
                }
                if(node->left){
                    if(!vis.count(node->left)){
                        q.push(node->left);
                        vis[node->left]=true;
                    }
                }
                if(node->right){
                    if(!vis.count(node->right)){
                        q.push(node->right);
                        vis[node->right]=true;
                    }
                }
                if(m[node]){
                    if(!vis.count(m[node])){
                        q.push(m[node]);
                        vis[m[node]]=true;
                    }
                }
            }
        }
        return ans;
    }
};
static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();