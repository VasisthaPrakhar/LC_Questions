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
class BSTIterator {
    private: stack<TreeNode*>s;
    vector<int>a;
    int idx=-1,n;
    void fun(TreeNode* root){
        if(root==nullptr){
            return;
        }
        fun(root->left);
        a.push_back(root->val);
        fun(root->right);
    }
public:
    BSTIterator(TreeNode* root) {
        // while(root){
        //     s.push(root);
        //     root=root->left;
        // }
        fun(root);
        n=a.size();
    }
    
    int next() {
        // TreeNode *t=s.top();
        // s.pop();
        // int val=t->val;
        // t=t->right;
        // while(t){
        //     s.push(t);
        //     t=t->left;
        // }
        // return val;
        return a[++idx];
    }
    
    bool hasNext() {
        //return !s.empty();
        return idx<n-1;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */