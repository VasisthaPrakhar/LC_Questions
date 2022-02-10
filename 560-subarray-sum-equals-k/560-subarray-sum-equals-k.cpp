class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        int s=0,ans=0;
        m[0]=1;
        for(auto x:nums){
            s+=x;
            if(m.find(s-k)!=m.end()){
                ans+=m[s-k];
            }
            m[s]++;
        }
        return ans;
    }
};