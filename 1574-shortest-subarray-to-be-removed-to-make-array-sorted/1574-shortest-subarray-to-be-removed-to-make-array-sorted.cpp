class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& nums) {
        int n=nums.size(),c=1;
        vector<int>pre(n,0),suf(n,0);
        for(int i=0;i<n;i++){
            if(i!=0){
                if(nums[i]>=nums[i-1]){
                    c++;
                }else{
                    c=1;
                }
            }
            pre[i]=c;
        }
        c=1;
        for(int i=n-1;i>=0;i--){
            if(i!=n-1){
                if(nums[i]<=nums[i+1]){
                    c++;
                }else{
                    c=1;
                }
            }
            suf[i]=c;
        }
        int ans=max(suf[0],pre[n-1]);
        map<int,int>m;
        for(int i=n-1;i>=0;i--){
            auto f=m.lower_bound(nums[i]);
            if(f!=m.end()){
                //cout<<i<<" "<<nums[i]<<" "<<pre[i]<<" "<<n-f->second<<" ("<<f->second<<", "<<f->first<<") "<<suf[f->second]<<endl;
                if(pre[i]==i+1 && suf[f->second]==n-f->second){
                    ans=max(ans,pre[i]+suf[f->second]);
                }
            }
            if(m.count(nums[i])){
                if(suf[i]==n-i){
                    m[nums[i]]=i;
                }
            }else{
                if(suf[i]==n-i){
                    m[nums[i]]=i;
                }
            }
        }
        return n-ans;
    }
};