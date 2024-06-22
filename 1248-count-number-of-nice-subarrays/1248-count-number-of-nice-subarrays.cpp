class Solution {
public:
    // int fun(vector<int>&a,int k,int &n){
    //     int j=0,i=0,s=0,ans=0;
    //     while(j<n){
    //         s+=(a[j]%2);
    //         while(s>k && i<=j){
    //             s-=(a[i]%2);
    //             i++;
    //         }
    //         ans+=j-i+1;
    //         j++;
    //     }
    //     return ans;
    // }
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        // int j=0,i=0,ans=0,z=0;
        // map<int,int>m;
        // while(j<n){
        //     if(nums[j]%2){
        //         z++;
        //         m[j]++;
        //     }
        //     while(z>k && i<j){
        //         if(nums[i]%2){
        //             z--;
        //             m[i]--;
        //             if(m[i]==0){
        //                 m.erase(i);
        //             }
        //         }
        //         i++;
        //     }
        //     if(z==k){
        //         ans+=m.begin()->first-i+1;
        //     }
        //     j++;
        // }
        // return ans;
        auto p = [&] (int z)
        {
            int j=0,i=0,s=0,ans=0;
            while(j<n){
                s+=(nums[j]%2);
                while(s>z && i<=j){
                    s-=(nums[i]%2);
                    i++;
                }
                ans+=j-i+1;
                j++;
            }
            return ans;
        };
        return p(k)-p(k-1);
        //return fun(nums,k,n)-fun(nums,k-1,n);
    }
};