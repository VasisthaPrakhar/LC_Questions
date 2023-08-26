class Solution {
public:
    int kthFactor(int n, int k) {
        int ans=-1;
        for(int i=1;i<=n;i++){
            if(k==0){ans=i-1;break;}
            if(n%i==0){
                k--;
            }
        }
        if(ans==-1 && k==0){ans=n;}
        return ans;
    }
};