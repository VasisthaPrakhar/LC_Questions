class Solution {
public:
    int dp[3001][3001];
    int fun(int idx,int j,vector<int>&arr,string &s,string &t,int n,int m,int sz){
        if(j>=m){return sz-idx;}
        int i=0;
        if(idx>0){
            i=arr[idx-1]+1;
        }
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
        if(dp[idx][j]!=-1){
            return dp[idx][j];
        }
        int res=INT_MIN;
        if(s[i]==t[j]){
            res=max(res,fun(idx+1,j+1,arr,s,t,n,m,sz));
            res=max(res,1+fun(idx+1,j,arr,s,t,n,m,sz));
        }else{
            res=max(res,1+fun(idx+1,j,arr,s,t,n,m,sz));
        }
        
        return dp[idx][j]=res;        
    }
    int maxRemovals(string s, string t, vector<int>& arr) {
        if(s==t){return 0;}
        int n=s.length(),m=t.length(),sz=arr.size();
        memset(dp,-1,sizeof(dp));
        return fun(0,0,arr,s,t,n,m,sz);
    }
};
