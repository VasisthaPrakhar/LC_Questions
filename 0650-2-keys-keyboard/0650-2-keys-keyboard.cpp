typedef long long int ll;
class Solution {
public:
    int dp(vector<vector<ll>>&memo,int idx,int cp,int &n){
        if(idx>n){
            return 1000;
        }
        if(n==idx){
            return 0;
        }
        if(!memo[idx-1][cp-1]){
            double copy=2+dp(memo,idx+idx,idx,n);
            double paste=1+dp(memo,idx+cp,cp,n);
            //cout<<copy<<" "<<paste<<endl;
            memo[idx-1][cp-1]=(ll)min(copy,paste);
        }
        return memo[idx-1][cp-1];
    }
    int minSteps(int n) {
        // if(n==1){
        //     return 0;
        // }
        // vector<vector<ll>>memo(n,vector<ll>(n,0));
        // return 1+dp(memo,1,1,n);
        int res = 0;
        for(int i=2;i<=n;i++){
            while(n%i == 0){
                res+= i;
                n=n/i;
            }
            if(n==0){
                break;
            }
        }
        return res;
    }
};