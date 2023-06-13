class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int n=s.length();
        if(n==1){
            return 1;
        }
        int i=0,j=1,ans=0;
        map<int,int>m,m1;
        while(j<n){
            if(s[j]==s[j-1]){
                m[j-1]++;
            }
            while(i<j && m.size()>1){
                if(s[i]==s[i+1]){
                    m[i]--;
                }
                if(m[i]==0){
                    m.erase(i);
                }
                i++;
            }
            
            //cout<<i<<" ";
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};