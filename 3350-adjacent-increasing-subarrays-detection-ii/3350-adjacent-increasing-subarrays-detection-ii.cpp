class Solution {
public:
    bool check(vector<int>& nums,int k,int n,vector<int>&a){
        //cout<<k<<" "<<n<<endl;
        if((2*k)>n){
            return false;
        }
        for(int i=k-1;i<n-k;i++){
            if(a[i]>=k && a[i+k]>=k){
                return true;
            }
        }
        return false;
    }
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n=nums.size();
        vector<int>a(n,1);
        int c=1;
        for(int i=1;i<n;i++){
            if(nums[i-1]<nums[i]){
                c++;
            }else{
                c=1;
            }
            a[i]=c;
        }
        int beg=0,end=n,mid,ans;
        while(beg<end){
            mid=(beg+end)/2;
            //cout<<beg<<" "<<mid<<" "<<end<<endl;
            if(check(nums,mid,n,a)){
                beg=mid+1;
                ans=mid;
            }else{
                end=mid;
            }
        }
        return ans;
    }
};