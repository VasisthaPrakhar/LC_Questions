class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size(),sum=0;
        if(n==1){
            return nums[0]%k==0?1:0;
        }
        // vector<int>pre(n);
        // for(int i=0;i<n;i++){
        //     sum+=nums[i];
        //     pre[i]=sum;
        // }
        unordered_map<int,int>m;
        m[0]=1;
        int ans=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int temp=(sum%k);
            if(temp<0){
                temp+=k;
            }
            if(m.find(temp)!=m.end()){
                ans+=m[temp];
            }
            m[temp]++;
        }
        //cout<<-7%5;
        return ans;
    }
};