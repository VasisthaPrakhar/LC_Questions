class Solution {
public:
    typedef long long int ll;
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        ll n=nums.size(),ans=0;
        ll sum=0;
        // vector<ll>a;
        // for(int i=0;i<n;i++){
        //     sum+=nums[i];
        //     a.push_back(sum);
        // }
        // for(int i=0;i<n;i++){
        //     int s=0,j=i,z=0;
        //     while(j<n){
        //         s+=nums[j];
        //         z=((j-i+1)*nums[j])-s;
        //         if(z>k){
        //             break;
        //         }
        //         ans=max(ans,j-i+1);
        //         j++;
        //     }
        // }
        ll j=0,i=0;
        while(j<n){
            sum+=nums[j];
            while(i<j && (((j-i+1)*(ll)nums[j])-sum)>k){
                sum-=nums[i];
                i++;
            }
            ans=max(j-i+1,ans);
            j++;
        }
        return ans;
    }
};