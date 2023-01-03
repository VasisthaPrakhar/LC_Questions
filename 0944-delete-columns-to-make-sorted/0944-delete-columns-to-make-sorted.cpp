class Solution {
public:
    int minDeletionSize(vector<string>& s) {
        int n=s.size();
        int m=s[0].length();
        int ans=0;
        for(int j=0;j<m;j++){
            for(int i=0;i<n-1;i++){
                if(s[i][j]>s[i+1][j]){
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};