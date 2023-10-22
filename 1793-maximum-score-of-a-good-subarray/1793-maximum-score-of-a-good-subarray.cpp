class Solution {
public:
    int fun(stack<pair<int,int>>&s, vector<int>&pre, int n,int k){
        int ans=-1;
        while(!s.empty()){
            int val=s.top().first;
            int suf_idx = s.top().second;
            int suf=abs(suf_idx-k)+1;
            int f=lower_bound(pre.begin(),pre.end(),val)-pre.begin();
            int p=pre.size()-f;
            //cout<<suf<<" "<<p<<" "<<val<<endl;
            ans=max(val*(suf+p),ans);
            s.pop();
        }
        //cout<<endl;
        return ans;
    }
    int maximumScore(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        vector<int>pre,suf;
        int mi=nums[k],i;
        stack<pair<int,int>>s,s1;
        for(int i=k-1;i>=0;i--){
            if(mi>nums[i]){
                s1.push({mi,i+1});
                mi=nums[i];
                //cout<<mi<<"\n\n";
            }
            pre.push_back(mi);
        }
        if(i<=0 && pre.size()){s1.push({mi,0});}
        reverse(pre.begin(),pre.end());
        mi=nums[k];
        for(i=k+1;i<n;i++){
            if(mi>nums[i]){
                s.push({mi,i-1});
                mi=nums[i];
            }
            suf.push_back(mi);
        }
        if(i==n && suf.size()){s.push({mi,i-1});}
        reverse(suf.begin(),suf.end());
        return max(fun(s,pre,n,k),fun(s1,suf,n,k));
    }
};