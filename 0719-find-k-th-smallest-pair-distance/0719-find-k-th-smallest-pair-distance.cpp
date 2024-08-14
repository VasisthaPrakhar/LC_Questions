class Solution {
public:
    int check(vector<int>& nums,int k,int n){
        int j=0,cnt=0;
        for(int i=1;i<n;i++){
            while (nums[i] - nums[j] > k) {
                j++;
            }
            cnt += i - j;
        }
        return cnt;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int beg=0,end=1e9,mid,ans=-1;
        while(beg<end){
            mid=(beg+end)/2;
            int z=check(nums,mid,n);
            if(z>=k){
                ans=mid;
                end=mid;
            }else{
                beg=mid+1;
            }
        }
        return ans;
    }
};