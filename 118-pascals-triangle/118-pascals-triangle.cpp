class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>>ans(1,vector<int>(1,1));
        if(n==1){
            return ans;
        }
        for(int i=1;i<n;i++){
            vector<int>temp;
            temp.push_back(ans[i-1][0]);
            for(int j=1;j<i;j++){
                temp.push_back(ans[i-1][j]+ans[i-1][j-1]);
            }
            temp.push_back(ans[i-1][i-1]);
            ans.push_back(temp);
        }
        return ans;
    }
};