class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& in, vector<int>& ni) {
        int n=in.size();
        if(n==0){
            return {{ni[0],ni[1]}};
        }
        int beg=in[0][0],end=in[0][1],f=1;
        auto pos=lower_bound(in.begin(),in.end(),ni)-in.begin();
        if(pos==0){
            beg=ni[0];
            end=ni[1];
            f=0;
        }
        vector<vector<int>>ans;
        for(int i=0;i<=n;i++){
            if(f && i==pos){
                if(end>=ni[0]){
                    end=max(end,ni[1]);
                }
                else{
                    ans.push_back({beg,end});
                    beg=ni[0];
                    end=ni[1];
                }
                f=0;
            }
            if(i<n && end>=in[i][0]){
                end=max(end,in[i][1]);
            }else{
                ans.push_back({beg,end});
                if(i<n){
                    beg=in[i][0];
                    end=in[i][1];
                }
            }
        }
        return ans;
    }
};