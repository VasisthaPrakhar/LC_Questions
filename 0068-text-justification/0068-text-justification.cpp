class Solution {
public:
    string fun(string &s,int w){
        stringstream ss(s);
        string t;
        vector<string>a;
        int k=0;
        while(getline(ss,t,' ')){
            if(t.length()>0){
                k+=t.length();
                a.push_back(t);
            }
        }
        int r=w-k;
        int n=a.size()-1;
        if(n==0){
            while(a[0].size()!=w){
                a[0].push_back(' ');
            }
            return a[0];
        }
        int sp=r/n,rsp=r%n;
        string ans="",sps="";
        while(sp){
            sps.push_back(' ');
            sp--;
        }
        for(int i=0;i<a.size()-1;i++){
            ans+=a[i]+sps;
            if(rsp){
                ans+=" ";
                rsp--;
            }
        }
        ans+=a[n];
        return ans;
        
    }
    vector<string> fullJustify(vector<string>& words, int w) {
        map<string,int>m;
        for(auto x:words){
            m[x]=x.length();
        }
        string ans="";
        vector<string>res;
        for(auto x:words){
            string t=ans+x;
            if(t.length()==w){
                res.push_back(t);
                ans="";
            }else if(t.length()>w){
                res.push_back(fun(ans,w));
                if(x.length()==w){
                    res.push_back(x);
                    ans="";
                }else{
                    ans=x;
                    ans.push_back(' ');
                }
            }else{
                ans=t;
                ans.push_back(' ');
            }
        }
        if(ans.size()>0){
            while(ans.size()!=w){
                ans.push_back(' ');
            }
            res.push_back(ans);
        }
        return res;
    }
};