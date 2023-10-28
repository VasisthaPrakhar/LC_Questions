class Solution {
public:
    int sumCounts(vector<int>& nums) {
         int n=nums.size();
        int j=0,i=0;
        map<int,int>m,m1;
        long long int ans=0;
        while(j<n){
            m[nums[j]]++;
            i=0;
            m1=m;
            while(i<=j){
                int k=m1.size();
                ans+=(k*k);
                m1[nums[i]]--;
                if(m1[nums[i]]==0){
                    m1.erase(nums[i]);
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};