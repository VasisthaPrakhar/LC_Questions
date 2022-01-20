class Solution {
public:
    string decodeString(string s) {
        int n=s.length();
        int j=0;
        stack<char>s1;
        string ans="";
        while(j<n){
            if(s[j]!=']'){
                s1.push(s[j]);
            }else{
                string temp="";
                while(!s1.empty() && s1.top()!='['){
                    temp=s1.top()+temp;
                    s1.pop();
                }
                s1.pop();
                string temp1="";
                while(!s1.empty() && isdigit(s1.top())){
                    temp1=s1.top()+temp1;
                    s1.pop();
                }
                int k=stoi(temp1);
                while(k--){
                    for(auto x:temp){
                        s1.push(x);
                    }
                }
            }
            j++;
        }
        while(!s1.empty()){
            ans=s1.top()+ans;
            s1.pop();
        }
        return ans;
    }
};
static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();