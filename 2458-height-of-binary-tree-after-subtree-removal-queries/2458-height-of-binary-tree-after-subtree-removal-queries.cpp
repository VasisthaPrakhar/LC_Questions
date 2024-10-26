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
    unordered_map<int,int>mp;
    int fun(TreeNode* root){
        if(root==NULL){
            return -1;
        }
        int l=1+fun(root->left);
        int r=1+fun(root->right);
        return mp[root->val]=max(l,r);
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& qu) {
        vector<int>ans;
        mp.clear();
        mp[root->val]=0;
        fun(root);
        int h=0;
        queue<TreeNode*>q;
        q.push(root);
        map<int,int>pre;
        while(!q.empty()){
            int sz=q.size();
            vector<int>a;
            priority_queue<int>pq;
            while(sz--){
                auto node=q.front();
                q.pop();
                a.push_back(node->val);
                int total=h+mp[node->val];
                pq.push(total);
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            for(auto x:a){
                int t=h+mp[x];;
                if(t==pq.top()){
                    pq.pop();
                    if(pq.empty()){
                        pre[x]=h-1;
                    }else{
                        pre[x]=pq.top();
                    }
                    pq.push(t);
                }else{
                    pre[x]=pq.top();
                }
            }
            h++;
        }
        for(auto x:qu){
            ans.push_back(pre[x]);
            //cout<<pre[x]<<endl;
        }
        return ans;
    }
};