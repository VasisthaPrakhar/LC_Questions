class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n=s.length(),c=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                c++;
            }
        }
        string ans="";
        while(c>1){
            ans.push_back('1');
            c--;
        }
        while(ans.size()<n-1){
            ans.push_back('0');
        }
        ans.push_back('1');
        return ans;
    }
};