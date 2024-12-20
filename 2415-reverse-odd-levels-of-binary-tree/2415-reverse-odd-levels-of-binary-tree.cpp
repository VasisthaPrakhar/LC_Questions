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
    void fun(vector<TreeNode*> &a){
        int n=a.size();
        int i=0,j=n-1;
        while(i<j){
            swap(a[i]->val,a[j]->val);
            i++,j--;
        }
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(root==NULL){return root;}
        int k=0;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int sz=q.size();
            vector<TreeNode*>arr;
            while(sz--){
                auto node=q.front();
                q.pop();
                if(k%2){
                    arr.push_back(node);
                }
                if(node->left){
                    q.push(node->left);
                    q.push(node->right);
                }
            }
            if(k%2){
                fun(arr);
            }
            k++;
        }
        return root;
    }
};