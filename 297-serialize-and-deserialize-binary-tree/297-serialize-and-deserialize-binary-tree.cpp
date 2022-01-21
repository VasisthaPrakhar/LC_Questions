/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==nullptr){
            return "#";
        }
        string s="";
        queue<TreeNode*>q;
        q.push(root);
        s+=(to_string(root->val));
        s.push_back(' ');
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            if(node->left==nullptr){
                s+="# ";
            }else{
                s+=(to_string(node->left->val));
                s.push_back(' ');
                q.push(node->left);
            }
            if(node->right==nullptr){
                s+="# ";
            }else{
                s+=(to_string(node->right->val));
                s.push_back(' ');
                q.push(node->right);
            }
        }
        //cout<<s<<" ";
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0){
            return nullptr;
        }
        stringstream ss(data);
        string s;
        getline(ss,s,' ');
        TreeNode* t;
        if(s=="#"){
            t=nullptr;
        }else{
            t=new TreeNode(stoi(s));
            queue<TreeNode*>q;
            q.push(t);
            while(!q.empty()){
                auto node=q.front();
                q.pop();
                getline(ss,s,' ');
                if(s=="#"){
                    node->left=nullptr;
                }else{
                    TreeNode* l=new TreeNode(stoi(s));
                    node->left=l;
                    q.push(node->left);
                }
                getline(ss,s,' ');
                if(s=="#"){
                    node->right=nullptr;
                }else{
                    TreeNode* r=new TreeNode(stoi(s));
                    node->right=r;
                    q.push(node->right);
                }
            }
        }
        return t;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));