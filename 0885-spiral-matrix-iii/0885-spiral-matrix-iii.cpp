class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int r, int c, int rs, int cs) {
        int n=r;
        int m1=c;
        vector<vector<int>>ans;
        unordered_map<int,vector<int>>m;
        m[0]={0,1};
        m[1]={1,0};
        m[2]={0,-1};
        m[3]={-1,0};
        set<pair<int,int>>vis;
        int dir=0,i=rs,j=cs,k1=1;
        while(ans.size()<n*m1){
            int z=2,k=k1++;
            while(z){
                int x=k;
                while(x){
                    if(i>=0 && i<n && j>=0 && j<m1 && vis.find({i,j})==vis.end()){
                        ans.push_back({i,j});
                        vis.insert({i,j});
                    }
                    i=i+m[dir][0];
                    j=j+m[dir][1];
                    x--;
                }
                dir=(dir+1)%4;
                z--;
            }
            //cout<<ans.size()<<endl;
        }
        return ans;
    }
};