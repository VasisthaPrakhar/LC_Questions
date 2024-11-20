class Solution {
public:
    bool check(unordered_map<char,int>&m,int k){
        return (m['a']>=k) && (m['b']>=k) && (m['c']>=k) && m['z']>0;
    }
    int takeCharacters(string &s, int k) {
        int sz=s.length();
        if(k==0){return 0;}
        if(sz<3){return -1;}
        string t=s+"z"+s;
        int j=0,i=0,n=t.length(),ans=INT_MAX;
        unordered_map<char,int>m;
        while(j<n){
            m[t[j]]++;
            while(i<=j && check(m,k)){
                ans=min(ans,j-i+1);
                m[t[i]]--;
                i++;
            }
            j++;
        }
        return (ans==INT_MAX || (ans-1)>sz)?-1:ans-1;
    }
};