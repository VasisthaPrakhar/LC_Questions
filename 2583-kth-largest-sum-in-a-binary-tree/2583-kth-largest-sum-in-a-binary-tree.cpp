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
    typedef long long int ll;
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*>q;
        priority_queue<ll>pq;
        q.push(root);
        while(!q.empty()){
            ll sz=q.size(),s=0;
            while(sz--){
                auto node=q.front();
                q.pop();
                s+=node->val;
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            pq.push(s);
        }
        while(!pq.empty() && k>1){
            k--;
            pq.pop();
        }
        if(pq.empty()){
            return -1;
        }else{
            return pq.top();
        }
    }
};