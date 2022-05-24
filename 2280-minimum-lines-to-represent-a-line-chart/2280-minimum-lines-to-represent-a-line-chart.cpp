class Solution {
public:
    int minimumLines(vector<vector<int>>& s) {
        int n=s.size();
        sort(s.begin(),s.end());
        long double x1=s[0][0],y1=s[0][1],x2,y2,m;
        long double prev=1000000007;
        int ans=0;
        for(int i=1;i<n;i++){
            x2=s[i][0],y2=s[i][1];
            m=((y2-y1)/(x2-x1));
            if(m==prev){
                x1=x2;
                y1=y2;
            }else{
                prev=m;
                x1=x2;
                y1=y2;
                ans++;
            }
        }
        return ans;
    }
};