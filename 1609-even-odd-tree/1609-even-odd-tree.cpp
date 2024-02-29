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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int k=0;
        map<int,vector<int>>mp;
        while(!q.empty()){
            int sz=q.size();
            vector<int>arr;
            while(sz--){
                auto node =q.front();
                q.pop();
                arr.push_back(node->val);
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            mp[k]=arr;
            k++;
        }
        for(auto &x:mp){
            if(x.first%2){
                int n=x.second.size();
                if(x.second[0]%2){return false;}
                for(int i=1;i<n;i++){
                    if(x.second[i]%2){return false;}
                    if(x.second[i-1]<=x.second[i]){
                        return false;
                    }
                }
            }else{
                int n=x.second.size();
                if(x.second[0]%2==0){return false;}
                for(int i=1;i<n;i++){
                    if(x.second[i]%2==0){return false;}
                    if(x.second[i-1]>=x.second[i]){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};