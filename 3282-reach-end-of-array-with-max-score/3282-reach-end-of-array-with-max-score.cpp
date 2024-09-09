class Solution {
public:
    typedef long long int ll;
    long long findMaximumScore(vector<int>& nums) {
        int n=nums.size();
        stack<pair<ll,int>>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[i]>st.top().first){
                st.pop();
            }
            st.push({nums[i],i});
        }
        ll ans=0;
        while(!st.empty()){
            auto k=st.top();
            st.pop();
            int j=0;
            if(!st.empty()){
                j=st.top().second;
            }else{
                j=n-1;
            }
            ans+=(ll)(j-k.second)*(ll)k.first;
        }
        return ans;
    }
};