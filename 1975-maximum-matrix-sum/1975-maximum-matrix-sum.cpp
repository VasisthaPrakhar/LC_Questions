class Solution {
public:
    typedef long long int ll;
    long long maxMatrixSum(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size(),ma=INT_MAX,c=0;
        ll sum=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]<=0){
                    c++;
                }
                ma=min(abs(mat[i][j]),ma);
                sum+=abs(mat[i][j]);
            }
        }
        //cout<<c<<" "<<ma<<endl;
        if(c%2){
            sum-=2*ma;
        }
        return sum;
    }
};