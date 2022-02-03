class Solution {
public:
    int fun(vector<int>&a){
        int ans=INT_MIN,curr=0;
        for(int i=0;i<a.size();i++){
            curr=max(curr+a[i],a[i]);
            ans=max(curr,ans);
        }
        return ans;
    }
    int fun1(vector<int>&a){
        int ans=INT_MAX,curr=0;
        for(int i=0;i<a.size();i++){
            curr=min(curr+a[i],a[i]);
            ans=min(curr,ans);
        }
        return ans;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        std::ios_base::sync_with_stdio(0);
        cin.tie(0);
        int sum=accumulate(nums.begin(),nums.end(),0);
        int ma=fun(nums);
        int mi=sum-fun1(nums);
        if(mi!=0)
        return ma>mi?ma:mi;
        return ma;
    }
};