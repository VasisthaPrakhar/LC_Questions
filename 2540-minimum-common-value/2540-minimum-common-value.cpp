class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        int ans=INT_MAX;
        for(auto x:nums1){mp[x]++;}
        for(auto x:nums2){
            if(mp.find(x)!=mp.end()){
                ans=min(ans,x);
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};