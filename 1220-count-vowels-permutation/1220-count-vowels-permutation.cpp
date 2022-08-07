class Solution {
private:
    int mod=1000000007;
public:
    vector<char>vow={'a','e','i','o','u'};
    int dp(int idx,int prev,unordered_map<int,map<int,int>>&m,int n){
        if(idx==n){
            return 1;
        }
        if(!m.count(idx) || !m[idx].count(prev)){
            int res=0;
            if(idx==0){
                for(int i=0;i<5;i++){
                    res=(res + dp(idx+1,i,m,n)%mod)%mod;
                }
            }else{
                if(prev==0){
                    res=(res+dp(idx+1,1,m,n)%mod)%mod;
                }else if(prev==1){
                    res=(res + dp(idx+1,0,m,n)%mod)%mod;
                    res=(res + dp(idx+1,2,m,n)%mod)%mod;
                }else if(prev==2){
                    for(int i=0;i<5;i++){
                        if(i!=2)
                            res=(res+dp(idx+1,i,m,n)%mod)%mod;
                    }
                }else if(prev==3){
                    res=(res+dp(idx+1,2,m,n)%mod)%mod;
                    res=(res+dp(idx+1,4,m,n)%mod)%mod;
                }else{
                    res=(res+dp(idx+1,0,m,n)%mod)%mod;
                }
            }
            //cout<<res;
            m[idx][prev]=res%mod;
        }
        return m[idx][prev];
    }
    int countVowelPermutation(int n) {
        unordered_map<int,map<int,int>>m;
        return dp(0,0,m,n);
    }
};