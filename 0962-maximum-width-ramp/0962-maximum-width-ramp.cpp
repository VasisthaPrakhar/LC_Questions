class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            v.push_back({nums[i],i});
        }
        sort(v.begin(),v.end(),[](pair<int,int>&a, pair<int,int>&b)->bool{
            if(a.first==b.first){
                return a.second<b.second;
            }
            return a.first<b.first;
        });
        int ma=v[n-1].second,ans=0;
        for(int i=n-1;i>=0;i--){
            ans=max(ma-v[i].second,ans);
            ma=max(ma,v[i].second);
        }
        return ans;
    }
};