class Solution {
public:
    bool check(int a,map<int,int>&m){
        bool res=true;
        for(auto x:m){
            int rem=x.second%a;
            if(rem!=0 && (rem!=a-1) && rem<a-1-(x.second/a)){
                res= false;
                break;
            }
        }
        // if(!res){
        //     for(auto x:m){
        //         int rem=x.second%a;
        //         if(rem!=0 && (rem!=1)){
        //             res= false;
        //             break;
        //         }
        //     }
        // }
        return res;
    }
    int minGroupsForValidAssignment(vector<int>& nums) {
        int n=nums.size();
        map<int,int>freq;
        for(auto x:nums){
            freq[x]++;
        }
        int mi=INT_MAX;
        for(auto x:freq){
            mi=min(mi,x.second);
        }
        if(mi==n){
            return 1;
        }
        int beg=2,end=mi+1,mid,ans=1;
        // while(beg<=end){
        //     mid=(beg+end)/2;
        //     if(check(mid,freq)){
        //         ans=mid;
        //         beg=mid+1;
        //     }else{
        //         end=mid-1;
        //     }
        // }
        for(int i=1;i<=mi+1;i++){
            if(check(i,freq)){
                ans=i;
            }
        }
        int res=0;
        cout<<ans<<" ";
        for(auto x:freq){
            res+=ceil((double)x.second/(double)ans);
        }
        return res;
    }
};