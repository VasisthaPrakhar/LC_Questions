class Solution {
public:
    int dif(int a,int b){
        int c=0;
        for(int i=0;i<32;i++){
            int k=1<<i;
            if((a&k)!=(b&k)){
                c++;
            }
        }
        return c;
    }
    int minOperations(vector<int>& nums, int k) {
        int n=nums.size(),z=0;
        for(int i=0;i<n;i++){
            z=z^nums[i];
        }
        if(k==z){
            return 0;
        }
        cout<<z;
        return dif(z,k);
        // int ans=INT_MAX;
        // for(int i=0;i<n;i++){
        //     int t=nums[i]^z;
        //     int s=k^t;
        //     cout<<s<<" ";
        //     ans=min(nums[i],s);
        // }
        // return ans;
    }
};