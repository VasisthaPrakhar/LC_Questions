class Solution {
public:
    int findLongestChain(vector<vector<int>>& p) {
        int n=p.size();
        sort(p.begin(),p.end(),[](vector<int> &a,vector<int>&b)->bool{
            return a[1]<b[1];
        });
        int ans=0,c=1,end=p[0][1];
        for(int i=1;i<n;i++){
            if(p[i][0]>end){
                c++;
                end=p[i][1];
            }
        }
        return c;
    }
};