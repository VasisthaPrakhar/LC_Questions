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
        // stack<char>t;
        // t.push(num[0]);
        // for(int i=1;i<n;i++){
        //     while(k>0 && !t.empty() && num[i]<t.top()){
        //         k--;
        //         t.pop();
        //     }
        //     t.push(num[i]);
        //     if(num[i]=='0' && t.size()==1){
        //         t.pop();
        //     }   
        // }
        // while(k>0 && !t.empty()){
        //     k--;
        //     t.pop();
        // }
        // while(!t.empty()){
        //     ans=t.top()+ans;
        //     t.pop();
        // }
        for(char &x:num){
            while(ans.length() && k>0 && x<ans.back()){
                ans.pop_back();
                k--;
            }
            ans.push_back(x);
        }
        while(!ans.empty() && k > 0){
            ans.pop_back();
            k--;
        }
        int i;
        for(i=0;i<ans.length();i++){
            if(ans[i]!='0'){
                break;
            }
        }
        return ans.length()==i?"0":ans.substr(i);
    }
};