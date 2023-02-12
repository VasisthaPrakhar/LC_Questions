class Solution {
public:
    string fun(int n){
        if(n==0){
            return "0";
        }
        string res="";
        while(n){
            res=to_string(n%2)+res;
            n/=2;
        }
        return res;
    }
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& qu) {
        vector<vector<int>>ans;
        unordered_map<long long int,vector<int>>m;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                if(!m.count(0))
                    m[0]={i,i};
                continue;
            }
            long long int k=0;
            for(int j=i;j<=min(i+32,n-1);j++){
                k=(k<<1) + s[j]-'0';
                if(!m.count(k))
                    m[k]={i,j};
            }
        }
        for(auto x:qu){
            long long int k=x[0]^x[1];
            if(m.find(k)!=m.end()){
                ans.push_back(m[k]);
                continue;
            }
            m[k]={-1,-1};
            ans.push_back(m[k]);
        }
        return ans;
    }
};