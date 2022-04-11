class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n=s.length();
        unordered_map<char,int>m;
        for(auto x:s){
            m[x]++;
        }
        int mi=INT_MAX;
        for(auto x:m){
            mi=min(mi,x.second);
        }
        if(mi==1){
            return false;
        }
        int l=n/mi;
        for(;l<=n/2;l++){
            int k=0,flag=0;
            string temp=s.substr(k,l);
            k+=l;
            while(k<n){
                string temp1=s.substr(k,l);
                if(temp!=temp1){
                    flag=1;
                    break;
                }
                k+=l;
            }
            if(flag==0){
                return true;
            }
        }
        return false;        
    }
};