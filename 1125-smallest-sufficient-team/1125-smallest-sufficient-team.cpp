class Solution {
public:
    unordered_map<int,unordered_map<int,vector<int>>>mp;
    int count(int n){
        int c=0;
        while(n){
            n&=(n-1);
            c++;
        }
        return c;
    }
    vector<int> fun(map<string,int>&m, int n, vector<vector<string>>&p, int n1, int idx, int k){
        if(count(k)==n){
            return {};
        }
        if(mp.find(idx)!=mp.end()){
            if(mp[idx].find(k)!=mp[idx].end()){
                return mp[idx][k];
            }
        }
        if(idx==n1){
            return {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
        }
        vector<int>res1;
        int x=0;
        for(auto y:p[idx]){
            x=x|(1<<m[y]);
        }
        if(k < (k|x)){
            res1=fun(m,n,p,n1,idx+1,k|x);
            res1.push_back(idx);
        }else{
            res1={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
        }
        vector<int>res=fun(m,n,p,n1,idx+1,k);
        return mp[idx][k]=(int)res.size()<(int)res1.size()?res:res1;
    }
    vector<int> smallestSufficientTeam(vector<string>& re, vector<vector<string>>& p) {
        int n=re.size();
        map<string,int>m;
        for(int i=0;i<n;i++){
            m[re[i]]=i+1;
        }
        int n1=p.size();
        mp.clear();
        return fun(m,n,p,n1,0,0);
    }
};