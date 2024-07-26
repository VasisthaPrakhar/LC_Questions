class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<long long int>>g(n,vector<long long int>(n,INT_MAX));
        for(int i=0;i<edges.size();i++){
            g[edges[i][0]][edges[i][1]]=edges[i][2];
            g[edges[i][1]][edges[i][0]]=edges[i][2];
        }
        for(int i=0;i<g.size();i++){g[i][i]=0;}  
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                for(int k=0;k<n;k++) {
                    if (g[j][k] > (g[j][i] + g[i][k]) && (g[i][k] != INT_MAX && g[j][i] != INT_MAX))
                        g[j][k] = g[j][i] + g[i][k];
                }
            }
        }
        vector<int>cnt(n,0);
         for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(g[i][j]<=distanceThreshold){
                    cnt[i]++;
                }
            }
        }
        int mi=INT_MAX,ans=0;
        for(int i=0;i<n;i++){
            if(mi>=cnt[i]){
                mi=cnt[i];
                ans=i;
            }
        }
        return ans;
    }
};