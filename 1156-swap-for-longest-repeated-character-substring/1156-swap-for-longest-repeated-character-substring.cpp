class Solution {
public:
    char ma(map<char,int>&m){
        int mama=INT_MIN;
        char ch;
        for(auto &x:m){
            if(mama<x.second){
                mama=x.second;
                ch=x.first;
            }
        }
        return ch;
    }
    bool check(map<char,int>&m){
        if(m.size()>2){
            return false;
        }
        int mi=INT_MAX;
        for(auto &x:m){
            mi=min(mi,x.second);
        }
        return mi<=1;
    }
    int maxRepOpt1(string text) {
        int ans=0,n=text.length();
        map<char,int>m,m1;
        char ch;
        for(auto x:text){
            m1[x]++;
        }
        int i=0,j=0;
        while(j<n){
            m[text[j]]++;
            if(m.size()==1 || check(m)){
                ans=max(ans,j-i+1);
                ch=ma(m);
            }else{
                while(i<=j && !check(m)){
                    m[text[i]]--;
                    if(m[text[i]]==0){
                        m.erase(text[i]);
                    }
                    i++;
                }
            }
            j++;
        }
        if(m1[ch]>=ans)
            return ans;
        else
            return ans-1;
    }
};