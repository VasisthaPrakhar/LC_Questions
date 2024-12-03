class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans="";
        int i=0,n=s.length(),j=0,m=spaces.size();
        while(i<n){
            if(j<m && i==spaces[j]){
                ans+=' ';
                j++;
            }
            ans+=s[i];
            i++;
        }
        return ans;
    }
};