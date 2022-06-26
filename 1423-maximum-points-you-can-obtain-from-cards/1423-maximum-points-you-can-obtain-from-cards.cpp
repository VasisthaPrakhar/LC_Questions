class Solution {
public:
    int maxScore(vector<int>& cp, int k) {
        int n=cp.size();
        int i=0,j=n-k,sum=0,ans=0,s=0;
        for(int i=0;i<n;i++){
            sum+=cp[i];
            if(i==n-k-1){
                ans=sum;
                s=sum;
            }
        }
        while(j<n){
            s-=cp[i];
            s+=cp[j];
            ans=min(s,ans);
            i++;
            j++;
        }
        return sum-ans;
    }
};