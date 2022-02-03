class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
       unordered_map<long long int,long long int>m12,m34;
        for(auto x:nums1){
            for(auto y:nums2){
                m12[x+y]++;
            }
        }
        for(auto x:nums3){
            for(auto y:nums4){
                m34[x+y]++;
            }
        }
        int ans=0;
        for(auto x:m12){
            long long int sum=-x.first;
            if(m34.count(sum)){
                // m34[sum]--;
                // if(m34[sum]==0){
                //     m34.erase(sum);
                // }
                ans+=x.second*m34[sum];
            }
        }
        return ans;
    }
};