class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.length();
        if(n<=k){
            return "0";
        }
        if(k==0){
            return num;
        }
        string ans="";
        stack<char>s,t;
        int idx=INT_MAX;
        for(int i=n-1;i>=0;i--){
            if(num[i]=='0'){
                idx=i;
            }
            s.push(num[i]);
        }
        t.push(s.top());
        s.pop();
        while(!s.empty()){
            while(k>0 && !t.empty() && s.top()<t.top()){
                k--;
                t.pop();
            }
            t.push(s.top());
            if(s.top()=='0' && t.size()==1){
                t.pop();
            }
            s.pop();
        }
        while(k>0 && !t.empty()){
            k--;
            t.pop();
        }
        while(!t.empty()){
            ans=t.top()+ans;
            t.pop();
        }
        return ans==""?"0":ans;
    }
};