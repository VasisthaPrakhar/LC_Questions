class Solution {
public:
    typedef long long int ll;
    int fun(vector<int>&nums, int n, int k){
        int l=-1,j=0,i=0,s=0;
        while(j<n){
            s+=nums[j];
            while(i<=j && s>k){
                s-=nums[i];
                i++;
            }
            if(s==k){
                l=max(l,j-i+1);
            }
            j++;
        }
        return l;
    }
    int fun1(vector<int>&nums, int n, int k){
        int l=INT_MAX,j=0,i=0,s=0;
        while(j<n){
            s+=nums[j];
            while(i<=j && s>k){
                s-=nums[i];
                i++;
            }
            if(s==k){
                l=min(l,j-i+1);
            }
            j++;
        }
        return l;
    }
    int minSizeSubarray(vector<int>& nums, int t) {
        int n=nums.size();
        ll sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        vector<int>a=nums;
        for(auto x:nums){
            a.push_back(x);
        }
        //cout<<sum;
        int k=sum-t%sum,f=(t/sum),res;
        if(f<=2){
            res=fun1(a,2*n,t);
        }else{
            res=fun1(a,2*n,t%sum);
        }
        long long int z=0;
        int ans=f*n;
        if(res==INT_MAX){
            z=(long long)ans-n + (long long)fun1(a,2*n,sum+t%sum);
        }else{
            if(f<=2){
                z=res;
            }else{
                z=ans+res;
            }
        }
        
        int l=fun(nums,n,k);
        //cout<<z<<" "<<l;
        if(l==-1 && z>=2*t){
            return -1;
        }else if(l==-1){
            return z;
        }else if(z>=INT_MAX){
            return ans+(n-l);
        }
        
        
        return min((long long)ans+(n-l),z);
    }
};