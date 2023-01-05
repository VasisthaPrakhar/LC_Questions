class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& p) {
        sort(p.begin(),p.end(),[](vector<int>&a,vector<int>&b)->bool{
          return a[1]<b[1]; 
        });
        int ans=0,mi=0;
        for(int i=0;i<p.size();i++){
            if(ans==0){
                ans++;
                mi=p[i][1];
            }
            else if(p[i][0]>mi){
                ans++;
                mi=p[i][1];
            }
            
        }
        return ans;
    }
};