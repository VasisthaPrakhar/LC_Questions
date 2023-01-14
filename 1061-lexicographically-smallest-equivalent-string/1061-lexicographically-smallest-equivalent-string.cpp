class Solution {
public:
    int findpar(int u,vector<int>&par){
        if(par[u]==-1 || par[u]==u)
            return u;
        return findpar(par[u],par);
    }
    void unionn(int u,int v,vector<int>&par){
        u=findpar(u,par);
        v=findpar(v,par);
        par[max(u,v)]=min(u,v);
    }
    string smallestEquivalentString(string s1, string s2, string b) {
        int n=s1.length();
        vector<int>par(26,-1);
        // for(int i=0;i<26;i++){
        //     par[i]=i;
        // }
        for(int i=0;i<n;i++){
            unionn(s1[i]-'a',s2[i]-'a',par);
        }
        string ans="";
        for(auto x:b){
            ans+=findpar(x-'a',par)+'a';
        }
        return ans;
    }
};