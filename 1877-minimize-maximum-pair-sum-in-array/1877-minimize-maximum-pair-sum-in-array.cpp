class Solution {
public:
    bool check(int n,int x,vector<int>&a){
        int i=0,j=n-1,c=0;
        while(i<j){
            if(a[i]+a[j]<=x){
                c++;
            }
            i++,j--;
        }
        if(c>=n/2){
            return true;
        }
        return false;
    }
    int minPairSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int end=nums[n-1]+nums[n-2], beg=nums[0]+nums[1],mid,ans=nums[n-1]+nums[n-2];
        while(beg<=end){
            mid=(beg+end)/2;
            int f=0;
            unordered_set<int>s;
            for(int i=0;i<n;i++){
                int k=mid-nums[i];
                if(s.find(k)!=s.end()){
                    f=1;
                    break;
                }
                s.insert(nums[i]);
            }
            if(f && check(n,mid,nums)){
                ans=mid;
                end=mid-1;
            }else{
                beg=mid+1;
            }
        }
        return ans;
    }
};