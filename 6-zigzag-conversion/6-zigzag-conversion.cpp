class Solution {
public:
    string convert(string s, int n) {
        if(n==1){
            return s;
        }
        int g=(n-1)*2;
        string ans;
        for(int i=0;i<n;i++){
            int j=i;
            int k=g-i;
            while(j<s.length() || k<s.length()){
                ans.push_back(s[j]);
                if(k % g != 0 && k<s.length() && j!=k) {
                    ans.push_back(s[k]);
                }
                j=j+g;
                k=k+g;
            }
        }
       // cout<<ans<<endl;
        return ans;
    }
};