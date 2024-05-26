// class Solution {
// public:
//     int numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
//     }
// };
class Solution {
public:
    typedef long long int ll;
    int numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size();
        int m=nums2.size();
        map<int,int>mp;
        for(int i=0;i<m;i++){
            mp[nums2[i]*k]++;
        }
        int ma=*max_element(nums1.begin(),nums1.end());
        int z=0,f=1;
        if(mp.begin()->first == 1){
            f=0;
            z=mp.begin()->second;
        }
        vector<int>seive(ma+2,z);
        for(auto x:mp){
            //cout<<x.first<<" "<<x.second<<endl;
            if(f==0){
                f++;
                continue;
            }
            for (ll i = x.first; i <= ma+1; i += x.first){
                seive[i] += x.second;
            }
        }
        // for(int i=0;i<ma+2;i++){
        //     cout<<seive[i]<<" ";
        // }
        ll ans=0;
        for(auto x:nums1){
            ans+=seive[x];
        }
        return ans;
    }
};