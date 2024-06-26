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
    void inorder(TreeNode* root,vector<int>&a){
        if(root==nullptr){
            return;
        }
        inorder(root->left,a);
        a.push_back(root->val);
        inorder(root->right,a);
    }
    TreeNode* build_tree(int beg,int end, vector<int>&a){
        if(beg>end){
            return NULL;
        }
        int mid=(beg+end)/2;
        TreeNode* root=new TreeNode(a[mid]);
        root->left=build_tree(beg,mid-1,a);
        root->right=build_tree(mid+1,end,a);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>a;
        inorder(root,a);
        int n=a.size();
        return build_tree(0,n-1,a);
    }
};