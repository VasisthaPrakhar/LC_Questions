class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n=nums.size();
        // int i,ans=0;
        // for(i=0;i<=n-k;i++){
        //     if(nums[i]==0){
        //         int j=i,z=0;
        //         while(z<k){
        //             nums[j]=nums[j]^1;
        //             z++,j++;
        //         }
        //         ans++;
        //     }
        // }
        // while(i<n){
        //     if(nums[i++]==0){
        //         return -1;
        //     }
        // }
        // return ans;
        int ans=0,flip=0;
        vector<int>a(n,0);
        for(int i=0;i<n;i++){
            if(i>=k){
                flip=(flip+a[i-k])%2;
            }
            if(flip==nums[i]){
                if(i+k>n){
                    return -1;
                }
                a[i]=1;
                flip=(flip+1)%2;
                ans++;
            }
        }
        return ans;
    }
};