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
// class Solution {
// public:
//     unordered_map<string,vector<TreeNode*>>m;
//     string fun(TreeNode* root){
//         if(root==nullptr){
//             return "";
//         }
//         string t="/"+fun(root->left)+to_string(root->val)+fun(root->right)+"/";
//         m[t].push_back(root);
//         return t;
//     }
//     vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
//         m.clear();
//         fun(root);
//         vector<TreeNode*>res;
//         for(auto x:m){
//             if(x.second.size()>1)
//                 res.push_back(x.second[0]);
//         }
//         return res;
//     }
// };
class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, vector<TreeNode*>> map;
        vector<TreeNode*> dups;
        serialize(root, map);
        for (auto it = map.begin(); it != map.end(); it++)
            if (it->second.size() > 1) dups.push_back(it->second[0]);
        return dups;
    }
private:
    string serialize(TreeNode* node, unordered_map<string, vector<TreeNode*>>& map) {
        if (!node) return "";
        string s = "(" + serialize(node->left, map) + to_string(node->val) + serialize(node->right, map) + ")";
        map[s].push_back(node);
        return s;
    }
};