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
    vector<TreeNode*> gt(int n,int base=0){
        vector<TreeNode*> ans;
        if (n == 0) {
            return { nullptr };
        }
        for (int i = 1; i <= n; i++) {
            for (auto left : gt(i - 1, base)) {
                for (auto right : gt(n - i, i + base)) {
					
                    ans.push_back(new TreeNode(i + base, left, right));
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> ans;
        ans=gt(n);
        return ans;
    }
};