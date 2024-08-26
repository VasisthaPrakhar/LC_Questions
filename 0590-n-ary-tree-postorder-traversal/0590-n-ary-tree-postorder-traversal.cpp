/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void fun(Node* root,vector<int>&a){
        if(root==nullptr){
            return;
        }
        for(auto x:root->children){
            fun(x,a);
        }
        a.push_back(root->val);
    }
    vector<int> postorder(Node* root) {
        vector<int>a;
        fun(root,a);
        return a;
    }
};