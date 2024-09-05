class Solution {
public:
    vector<int> missingRolls(vector<int>& r, int mean, int n) {
        int m=r.size();
        int sum=accumulate(r.begin(),r.end(),0);
        double k=((n+m)*mean)-sum;
        int z=k/n,y=(int)k%n;
        if((k/(double)n) > 6 || (k/(double)n) < 1){return {};}
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            if(y){
                ans[i]=z+1;
                y--;
            }else{
                ans[i]=z;
            }
        }
        return ans;
    }
};