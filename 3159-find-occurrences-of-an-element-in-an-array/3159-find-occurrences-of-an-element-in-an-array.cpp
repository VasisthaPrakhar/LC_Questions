class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& q, int x) {
        int n=nums.size();
        int m=q.size();
        map<int,vector<int>>mp;
        for(int i=0;i<n;i++){
            if(nums[i]==x){
                mp[x].push_back(i);
            }
        }
        vector<int>ans(m);
        for(int i=0;i<m;i++){
            if(q[i]>mp[x].size()){
                ans[i]=-1;
            }else{
                ans[i]=mp[x][q[i]-1];
            }
        }
        return ans;
    }
};