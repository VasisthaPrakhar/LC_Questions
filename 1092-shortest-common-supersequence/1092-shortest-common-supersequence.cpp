class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        int n=s1.length();
        int m=s2.length();
        int dp[n+1][m+1];
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        int p=n,q=m;
        string lcs;
        while(p>0 && q>0){
            if(s1[p-1]==s2[q-1]){
                lcs.push_back(s1[p-1]);
                p--;
                q--;
            }else{
                if(dp[p-1][q]>dp[p][q-1]){
                    p--;
                }else{
                    q--;
                }
            }
        }
        int n1=lcs.length();
        string ans;
        int i=n-1,j=m-1,k=0;
        while(k<n1){
            while(i>=0 && s1[i]!=lcs[k]){
                ans.push_back(s1[i]);
                i--;
            }
            i--;
            while(j>=0 && s2[j]!=lcs[k]){
                ans.push_back(s2[j]);
                j--;
            }
            j--;
            ans.push_back(lcs[k]);
            k++;
        }
        while(i>=0){
            ans.push_back(s1[i]);
            i--;
        }
        while(j>=0){
            ans.push_back(s2[j]);
            j--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};