class Solution {
public:
    typedef long long int ll;
    int minimizeMax(vector<int>& nums, int p) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        ll beg=0,end=nums[n-1]-nums[0],ans=0;
        while(beg<=end){
            ll mid=(beg+end)/2;
            int k=0;
            for(int i=1;i<n && k<p;i++){
                if(nums[i]-nums[i-1]<=mid){
                    k++,i++;
                }
            }
            if(k>=p){
                end=mid-1;
                ans=mid;
            }else{
                beg=mid+1;
            }
        }
        return ans;
    }
};