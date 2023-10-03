class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        map<int,int>s;
        int ans=0;
        for(auto x:nums){
            if(s.find(x)!=s.end()){
                ans+=s[x];
            }
            s[x]++;;
        }
        return ans;
    }
};