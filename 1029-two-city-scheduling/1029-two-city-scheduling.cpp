class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& c) {
        int n=c.size();
        if(n==0){
            return 0;
        }
        sort(c.begin(),c.end(),[](vector<int>&a,vector<int>&b)->bool{
            return (a[0]-a[1])<(b[0]-b[1]);
        });
        int sum=0;
        for(int i=0;i<n;i++){
            if(i<n/2){
                sum+=c[i][0];
            }else{
                sum+=c[i][1];
            }
            //cout<<sum<<endl;
        }
        return sum;
    }
};