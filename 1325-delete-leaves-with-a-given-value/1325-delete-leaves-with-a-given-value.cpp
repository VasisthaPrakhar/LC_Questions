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
    int fun(TreeNode* root, int t){
        if(root==nullptr){return 1;}
        if(root->left==NULL && root->right==NULL){
            if(root->val==t){
                return 1;
            }else{
                return 0;
            }
        }
        //int l=0,r=0;
        int l=fun(root->left,t);
        int r=fun(root->right,t);
        if(l==1){
            root->left=nullptr;
        }
        if(r==1){
            root->right=nullptr;
        }
        if(l==1 && r==1){
            if(root->val==t){
                return 1;
            }
        }
        return 0;
    }
    TreeNode* removeLeafNodes(TreeNode* root, int t) {
        fun(root,t);
        if(root->left==NULL && root->right==NULL){
            if(root->val==t){
                return nullptr;
            }else{
                return root;
            }
        }
        return root;
    }
};