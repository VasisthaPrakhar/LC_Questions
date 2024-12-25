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
    void swap(vector<int> &arr,int i, int j)
    {
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
    int mifun(vector<int>&arr)
    {
    int n=arr.size();
      int ans = 0;
      vector<int>temp = arr;
      map <int, int> h;
      sort(temp.begin(), temp.end());
      for (int i = 0; i < n; i++)
      {
        h[arr[i]] = i;
      }
      for (int i = 0; i < n; i++)
      {
        if (arr[i] != temp[i])
        {
          ans++;
          int init = arr[i];
          swap(arr, i, h[temp[i]]);
          h[init] = h[temp[i]];
          h[temp[i]] = i;
        }
      }
      return ans;
    }
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int ans=0;
        while(!q.empty()){
            int sz=q.size();
            vector<int>b;
            while(sz--){
                auto node=q.front();
                q.pop();
                b.push_back(node->val);
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            ans+=mifun(b);
        }
        return ans;
    }
};