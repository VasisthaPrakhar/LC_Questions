class Solution {
public:
        int maxSatisfaction(vector<int>& s) {
        sort(s.begin(),s.end());
        int n=s.size(),res=0,sum=0,ans=0;
        for(int i=n-1;i>=0;i--){
            ans+=sum+s[i];
            sum+=s[i];
            res=res>ans?res:ans;
        }
        return res;
    }
};