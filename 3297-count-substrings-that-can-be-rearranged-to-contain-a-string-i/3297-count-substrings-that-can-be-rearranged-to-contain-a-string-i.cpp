class Solution {
public:
    typedef long long int ll;
    long long validSubstringCount(string w1, string w2) {
        int n=w1.length(),m=w2.length();
        vector<int>a(26,0),b(26,0);
        for(int i=0;i<m;i++){
            a[w2[i]-'a']++;
        }
        ll j=0,i=0,ans=0,k=0;
        while(j<n){
            int z=w1[j]-'a';
            if(a[z]>0 && b[z]<a[z]){
                k++;
            }
            b[z]++;
            while(k==m){
                ans+=n-j;
                b[w1[i]-'a']--;  
                if(a[w1[i]-'a']>0 && b[w1[i]-'a']<a[w1[i]-'a'] ){
                    k--;
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};