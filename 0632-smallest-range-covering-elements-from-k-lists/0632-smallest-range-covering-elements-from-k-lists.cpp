class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k=nums.size();
        map<int,set<int>>mp;
        int z=0;
        for(auto x:nums){
            z++;
            for(auto y:x){
                mp[y].insert(z);
            }
        }
        unordered_map<int,int>m;
        vector<int>v;
        for(auto x:mp){
            v.push_back(x.first);
        }
        int n=v.size();
        int j=0,i=0,ans=INT_MAX,low=-1,high=-1;
        while(j<n){
            for(auto x:mp[v[j]]){
                m[x]++;
            }
            while(i<=j && m.size()>=k){
                if(ans>(v[j]-v[i]+1)){
                    ans=v[j]-v[i]+1;
                    low=v[i];
                    high=v[j];
                }
                for(auto x:mp[v[i]]){
                    m[x]--;
                    if(m[x]==0){
                        m.erase(x);
                    }
                }
                i++;
            }
            j++;
        }
        return {low,high};
    }
};