class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        set<int>s,vis;
        for(int i=0;i<n;i++){
            s.insert(nums[i]);
        }
        int ans=0;
        for(auto x:s){
            if(s.find(x-1)==s.end()){
                int k=x+1;
                while(s.count(k)){
                    k++;
                }
                ans=max(ans,k-x);
            }
        }
        return ans;
    }
};