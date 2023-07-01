class Solution {
public:
    int rob(vector<int>& a) {
        int n=a.size();
        int sum=0,ans=0;
        for(int i=0;i<n;i++){
            int k=max(ans,sum+a[i]);
            sum=ans;
            ans=k;
        }
        return ans;
    }
};