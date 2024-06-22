class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        int j=0,i=0,ans=0,z=0;
        map<int,int>m;
        while(j<n){
            if(nums[j]%2){
                z++;
                m[j]++;
            }
            while(z>k && i<j){
                if(nums[i]%2){
                    z--;
                    m[i]--;
                    if(m[i]==0){
                        m.erase(i);
                    }
                }
                i++;
            }
            if(z==k){
                ans+=m.begin()->first-i+1;
            }
            j++;
        }
        return ans;
    }
};