class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        int n=nums.size(),ans=0;
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        for(auto x:m){
            if(k==0){
                if(x.second>1){
                    ans++;
                }
            }else{
                if(m.count(x.first-k)){
                    ans++;
                }
            }
        }
        return ans;
    }
};