class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        int n=nums.size();
        map<int,int>mp,mp1;
        for(int i=0;i<n/2;i++){
            mp[abs(nums[i] - nums[n - i - 1])]++;
            int a=max(nums[i],nums[n - i - 1]);
            int b=k-min(nums[i],nums[n - i - 1]);
            mp1[max(a,b)]++;
        }
        for(int i=k-1;i>=0;i--){
            mp1[i]+=mp1[i+1];
        }
        int ans=INT_MAX;
        for(auto x:mp){
            int res=0;
            if(mp1[x.first]>=n/2){
                res=n/2-x.second;
            }else{
                res=mp1[x.first]-x.second;
                res+=(n/2-mp1[x.first])*2;
            }
            cout<<x.first<<": "<<x.second<<" "<<res<<endl;
            ans=min(ans,res);
        }
        return ans;
    }
};