class Solution {
public:
    string reverseParentheses(string s) {
        int n=s.length();
        string ans="";
        for(int i=0;i<n;i++){
            if(s[i]==')'){
                string t="";
                while(ans.back()!='('){
                    t.push_back(ans.back());
                    ans.pop_back();
                }
                ans.pop_back();
                ans+=t;
                cout<<ans<<endl;
            }else{
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};