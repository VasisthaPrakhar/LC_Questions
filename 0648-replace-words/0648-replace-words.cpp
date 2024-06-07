class Solution {
public:
    string replaceWords(vector<string>& d, string &s) {
        map<string,int>mp;
        for(auto x:d){
            mp[x]++;
        }
        stringstream ss(s);
        string token,ans="";
        while(getline(ss,token,' ')){
            int n=token.size(),f=0;
            for(int i=1;i<=n;i++){
                string temp=token.substr(0,i);
                if(mp.find(temp)!=mp.end()){
                    ans+=temp+" ";
                    f=1;
                    break;
                }
            }
            if(f==0){
                ans+=token + " ";
            }
        }
        ans.pop_back();
        return ans;
    }
};