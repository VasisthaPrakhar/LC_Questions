class Solution {
public:
    string largestOddNumber(string num) {
        int n=num.length();
        for(int i=n-1;i>=0;i--){
            int k=num[i]-'0';
            if(k%2){
                return num.substr(0,i+1);
            }
        }
        return "";
    }
};