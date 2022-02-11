class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s1.length(),m=s2.length();
        if(n>m){
            return false;
        }
        vector<int>m2(26,0);
        for(auto x:s1){m2[x-'a']++;}
        int l=0,r=n-1;
        vector<int>m1(26,0);
        int f=1;
        while(r<m){          
           if(f==1){
                for(int i=l;i<=r;i++){
                    m1[s2[i]-'a']++;
                }
               f++;
           }else{
               m1[s2[l-1]-'a']--;
               m1[s2[r]-'a']++;
           }
            if(m2==m1){
                return true;
            }
            l++,r++;
        }
        return false;
    }
};