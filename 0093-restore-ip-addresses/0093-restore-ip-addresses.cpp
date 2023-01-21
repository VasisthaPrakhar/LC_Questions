class Solution {
public:
    void fun(string &s, int idx, string t, int n, vector<string>&ans,int k){
        if(idx>=n){
            if(k==4){
                t.pop_back();
                ans.push_back(t);
            }
            //cout<<t<<endl;
            return;
        }
        for(int i=1;i<=min((n-idx),3);i++){
            string temp=s.substr(idx,i);
            if(i>1 && temp[0]=='0'){
                continue;
            }
            //cout<<temp<<endl;
            int z=stoi(temp);
            if(z<256){
                string x=t;
                t+=temp+".";
                fun(s,idx+i,t,n,ans,k+1);
                t=x;
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        int n=s.length();
        vector<string>ans;
        fun(s,0,"",n,ans,0);
        return ans;
    }
};