class Solution {
public:
    long long dividePlayers(vector<int>& sk) {
        int n=sk.size();
        sort(sk.begin(),sk.end());
        int i=0,j=n-1;
        long long sum=sk[i]+sk[j];
        long long int ans=sk[i]*sk[j];
        i++,j--;
        while(i<j){
            if(sk[i]+sk[j]!=sum){
                return -1;
            }
            ans+=sk[i]*sk[j];
            i++,j--;
        }
        return ans;
    }
};