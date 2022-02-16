class Solution {
public:
    Solution() {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
    }
    int minSubarray(vector<int>& nums, int p) {
        int n=nums.size();
        std::vector<long long int>pre(n);
        pre[0]=nums[0];
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]+nums[i];
        }
        int t=pre[n-1]%p;
        if(t==0){
            return 0;
        }
        std::unordered_map<int,int>m;
        m[0]=-1;
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            int temp=pre[i]%p;
            int k=(temp-t+p)%p;
            if(m.find(k)!=m.end()){
                ans=std::min(ans,i-m[k]);
            }
            m[temp]=i;
        }
        return ans>=n?-1:ans;
    }
};