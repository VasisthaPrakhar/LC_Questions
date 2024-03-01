class Solution {
public:
    typedef long long int ll;
    bool fun(int n,ll mid,ll sum,vector<int>& nums, vector<int>& ch){
        unordered_map<int,int>mp;
        for(int i=0;i<=mid;i++){
            mp[ch[i]]=i;
        }
        if(mp.size()!=n){return false;}
        ll su=0;
        for(int i=0;i<=mid;i++){
            su++;
            if(mp[ch[i]]==i){
                if(su<nums[ch[i]-1]+1){return false;}
                su-=nums[ch[i]-1]+1;
            }
        }
        return true;
    }
    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& ch) {
        int n=nums.size();
        int m=ch.size();
        ll sum=accumulate(nums.begin(),nums.end(),0LL);
        ll beg=sum+n-1,end=m-1,mid,ans=-1;
        while(beg<=end){
            mid=(beg+end)/2;
            if(fun(n,mid,sum,nums,ch)){
                ans=mid+1;
                end=mid-1;
            }else{
                beg=mid+1;
            }
        }
        return ans;
    }
};