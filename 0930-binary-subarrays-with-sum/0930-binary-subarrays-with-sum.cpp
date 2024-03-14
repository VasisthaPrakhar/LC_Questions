class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int s=0,c0=0,l=0,ans=0;
        for (int i = 0; i < nums.size(); ++i) {
            s+=nums[i];
            if(s == goal) {
                while (nums[l] == 0 && l < i){
                    l++;
                    c0++;
                } 
                ans+=1+c0;
            } 
            else if (s>goal) {
                while(s>goal){
                    s=s-nums[l];
                    l++;
                }
                c0=0;
                if(l>i) continue;
                s-= nums[i--];
            }
        }
        return ans;
    }
};