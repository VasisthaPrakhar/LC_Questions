class Solution {
public:
    int maxScore(string s) {
        int n=s.length();
        vector<int>a(n,0);
        int c=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                c++;
            }
            a[i]=c;
        }
        int ans=0;
        for(int i=0;i<n-1;i++){
            ans=max(ans,(a[n-1]-a[i])+(i+1 - a[i]));
        }
        return ans;
    }
};