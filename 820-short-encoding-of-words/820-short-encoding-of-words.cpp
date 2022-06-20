class Solution {
public:
    int minimumLengthEncoding(vector<string>& w) {
        unordered_set<string>s,s1;
        int n=w.size();
        sort(w.begin(),w.end(),[](string &a,string &b)->bool{
            return a.length()>b.length();
        });
        for(int i=0;i<n;i++){
            if(s.find(w[i])!=s.end()){
                continue;
            }else{
                string t="";
                int z=w[i].length();
                for(int j=z-1;j>=0;j--){
                    t=w[i][j]+t;
                    s.insert(t);
                }
                s1.insert(w[i]);
            }
        }
        int ans=0;
        for(auto x:s1){
            ans+=x.length();
            ans++;
        }
        return ans;
    }
};