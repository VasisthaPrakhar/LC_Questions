/*Definition for a binary tree node.
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* head=root;
        pair<TreeNode*,int>prev={nullptr,0};
        int f=1;
        while(root){
            if(root==nullptr){
                break;
            }
            if(root->val==key){
                f=0;
                break;
            }
            if(root->val<key){
                prev.first=root;
                prev.second=1;
                root=root->right;
            }else{
                prev.first=root;
                prev.second=2;
                root=root->left;
            }
        }
        if(f==1){
            return head;
        }else{
            if(prev.first==nullptr){
                TreeNode* temp=root;
                if(temp->left){
                    root=root->left;
                    head=root;
                    while(root->right){
                        root=root->right;
                    }
                    root->right=temp->right;
                }else{
                    head=root->right;
                }
                delete temp;
            }else{
                TreeNode* temp=root;
                if(prev.second==1){
                    if(root->left){
                        prev.first->right=root->left;
                        root=root->left;
                    }
                    else{
                        prev.first->right=root->right;
                    }
                }else{
                    if(root->left){
                        prev.first->left=root->left;
                        root=root->left;
                    }
                    else{
                        prev.first->left=root->right;
                    }
                }
                if(temp->left){
                    while(root->right){
                        root=root->right;
                    }
                    root->right=temp->right;
                }
                delete temp;
            }
        }
        return head;
    }
};
static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();