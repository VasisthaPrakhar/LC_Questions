class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int n=str1.length(),m=str2.length();
        int i=0,j=0;
        while(i<n && j<m){
            if((str1[i]-'a')%26 ==str2[j]-'a' || ((str1[i]-'a') + 1)%26==str2[j]-'a'){
                i++,j++;
            }else{
                i++;
            }
        }
        return (j==m);
    }
};