class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        map<vector<int>,int>mp;
        for(int i=0;i<n;i++){
            mp[grid[i]]++;
        }
        int ans=0;
        for(int i=0;i<m;i++){
            vector<int>a;
            for(int j=0;j<n;j++){
                a.push_back(grid[j][i]);
            }
            // for(auto x:a){
            //     cout<<x<<" ";
            // }
            // cout<<endl;
            ans+=mp[a];
        }
        return ans;
    }
};