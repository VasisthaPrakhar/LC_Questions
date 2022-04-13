class Solution{
public:
vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size()-1;
        int m=matrix[0].size()-1;
        int k=0,i=0,j=0,k1=n/2,n2=n+1,m2=m+1;
        vector<int>ans;
        while(k<=k1 && ans.size()!=(n2*m2)){
            if(i<=k&&j<=k){
                for(j=k;j<=m;j++){
                    ans.push_back(matrix[i][j]);
                }              
            }
            else if(i<=k&&j>=m){
                j--;
                for(i=k+1;i<=n;i++){
                   ans.push_back(matrix[i][j]);
                }
            }
            else if(i>=n&&j>=m){
                i--;
                for(j=m-1;j>=k;j--){
                    ans.push_back(matrix[i][j]);
                }
            }
            else if(i>=n&&j<=k){
                j++;
                for(i=n-1;i>k;i--){
                    ans.push_back(matrix[i][j]);
                }
                i++;
                k++;
                m--;
                n--;
            }
        
        }
        return ans;
    }
};