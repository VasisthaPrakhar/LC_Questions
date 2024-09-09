/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>>ans(m,vector<int>(n,-1));
        int i=0,j=0,f=0;
        unordered_map<int,pair<int,int>>mp;
        mp[0]={0,1};
        mp[1]={1,0};
        mp[2]={0,-1};
        mp[3]={-1,0};
        while(head){
            //cout<<i<<" "<<j<<endl;
            ans[i][j]=head->val;
            int nr=i+mp[f].first;
            int nc=j+mp[f].second;
            if(nr<0 || nr>=m || nc<0 || nc>=n || ans[nr][nc]!=-1){
                f=(f+1)%4;
                i=i+mp[f].first;
                j=j+mp[f].second;
            }else{
                i=nr,j=nc;
            }
            head=head->next;
        }
        return ans;
    }
};