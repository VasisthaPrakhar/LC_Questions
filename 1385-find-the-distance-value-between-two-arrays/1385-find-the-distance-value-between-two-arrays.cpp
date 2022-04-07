class Solution {
public:
    int findTheDistanceValue(vector<int>& a, vector<int>& b, int d) {
        int n=a.size();
        int m=b.size(),ans=0;
        for(int i=0;i<n;i++){
            int f=1;
            for(int j=0;j<m && f;j++){
                if(abs(a[i]-b[j])<=d){
                    f=0;
                }
            }
            if(f){
                ans++;
            }
        }
        return ans;
    }
};