/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* dfs(Node* node,unordered_map<int,Node*>&m){
        Node* temp=new Node(node->val);
        m[node->val]=temp;
        for(auto x:node->neighbors){
            if(m.find(x->val)==m.end())
            temp->neighbors.push_back(dfs(x,m));
            else{
                temp->neighbors.push_back(m[x->val]);
            }
        }
        return m[node->val];
    }
    Node* cloneGraph(Node* node) {
        if(node==nullptr){
            return node;
        }
        unordered_map<int,Node*>m;
        return dfs(node,m);
    }
};