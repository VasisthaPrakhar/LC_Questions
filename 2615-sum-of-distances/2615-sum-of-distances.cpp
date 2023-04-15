class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n=nums.size();
        map<int,vector<long long int>>pos;
        map<int,int>mp;
        for(int i=0;i<n;i++){
            if(pos.find(nums[i])!=pos.end())
                pos[nums[i]].push_back(i+pos[nums[i]].back());
            else
                pos[nums[i]].push_back(i);
            mp[i]=pos[nums[i]].size()-1;
        }
        vector<long long>ans(n,0);
        for(int i=0;i<n;i++){
            long long int res=0,k=mp[i];
            int m=pos[nums[i]].size();
            if(k!=0){
                res+=abs(((k)*i)-pos[nums[i]][k-1]);
            }
            if(k!=m-1){
                res+=abs(((m-k-1)*i)-(pos[nums[i]][m-1]-pos[nums[i]][k]));
            }
            ans[i]=res;
        }
        return ans;
    }
};