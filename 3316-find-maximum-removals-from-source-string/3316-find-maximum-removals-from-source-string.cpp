class Solution {
public:
    int dp[3001][3001];
    
    int fun(int idx,int i,int j,vector<int>&arr,string &s,string &t,int n,int m,int sz){
        if(j>=m){return sz-idx;}
        if(i>=n){return INT_MIN;}
        while(i<n && j<m){
            if(idx<sz &&  i==arr[idx]){
                break;
            }
            if(s[i]==t[j]){
                i++,j++;
            }else{
                i++;
            }
        }
        if(idx>=sz) {
            if(j>=m)
                return 0;
            else 
                return INT_MIN;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int res=INT_MIN,f=0;
        res=max(res,1+fun(idx+1,i+1,j,arr,s,t,n,m,sz));
        res=max(res,fun(idx+1,i,j,arr,s,t,n,m,sz));
        return dp[i][j]=res;        
    }
    int maxRemovals(string s, string t, vector<int>& arr) {
        if(s==t){return 0;}
        int n=s.length(),m=t.length(),sz=arr.size();
        memset(dp,-1,sizeof(dp));
        return fun(0,0,0,arr,s,t,n,m,sz);
    }
};
