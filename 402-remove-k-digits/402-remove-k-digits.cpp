class Solution {
public:
    string removeKdigits(string num, int k) {
        // int n=num.length();
        // if(n<=k){
        //     return "0";
        // }
        // if(k==0){
        //     return num;
        // }
        string ans;
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