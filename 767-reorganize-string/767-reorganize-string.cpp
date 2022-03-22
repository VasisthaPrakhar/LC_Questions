class Solution {
public:
    string reorganizeString(string s) {
        int n=s.length(),f=1;
        if(n==1){
            return s;
        }
        if(n==2){
            return s[0]==s[1]?"":s;
        }
        if(n%2){
            f=0;
        }
        unordered_map<char,int>m;
        priority_queue<pair<int,char>>st;
        for(auto x:s){
            m[x]++;
        }
        for(auto x:m){
            if((f && x.second>n/2) || (!f && x.second>(n/2+1))){
                return "";
            }
            st.push({x.second,x.first});
        }
        string ans;
        while(st.size()>1){
            bool f=false;
            auto it=st.top();
            st.pop();
            auto it1=st.top();
            st.pop();
            while(it.first!=0 && it1.first!=0){
                if(f){
                    ans.push_back(it1.second);
                    it1.first--;
                    f=!f;
                }else{
                    ans.push_back(it.second);
                    it.first--;
                    f=!f;
                }
            }
            if(it.first>0)
                st.push(it);
            if(it1.first>0)
                st.push(it1);
        }
        string res;
        if(st.size()){
            auto it=st.top();
            st.pop();
            if(it.first>1){
                int i=0;
                while(i<ans.size()){
                    if(it.first){
                        res.push_back(it.second);
                        it.first--;
                    }
                    res.push_back(ans[i++]);
                    if(i<ans.size())
                    res.push_back(ans[i++]);
                }
            }else{
                ans.push_back(it.second);
                res=ans;
            }
        }
        else{
            res=ans;
        }
        return res;
    }
};