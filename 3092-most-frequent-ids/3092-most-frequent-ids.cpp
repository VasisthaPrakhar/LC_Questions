class Solution {
public:
    typedef long long int ll;
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        int n=nums.size();
        unordered_map<ll,ll>m;
        map<ll,set<ll>,greater<ll>>mp;
        vector<ll>ans(n,0);
        for(int i=0;i<n;i++){
            if(mp.find(m[nums[i]])!=mp.end()){
                mp[m[nums[i]]].erase(nums[i]);
                if(mp[m[nums[i]]].size()==0){
                    mp.erase(m[nums[i]]);
                }
            }
            // for(auto x:m){
            //     cout<<x.first<<" "<<x.second<< "||";
            // }
            // cout<<endl;
            m[nums[i]]+=freq[i];
            if(m[nums[i]]>0){
                mp[m[nums[i]]].insert(nums[i]);
            }
            if(mp.size()){
                ans[i]=mp.begin()->first;
            }
        }
        return ans;
    }
};