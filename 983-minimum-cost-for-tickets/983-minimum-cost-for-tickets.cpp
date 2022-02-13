class Solution {
public:
    int dr[3]={1,7,30};
    int dp(vector<int>&d,int idx,vector<int>& c,unordered_map<int,int>&memo){
        if(idx>=d.size()){
            return 0;
        }
        if(!memo.count(idx)){
            int res=INT_MAX;
            int temp=idx;
            for(int i=0;i<3;i++){
                while(temp<d.size() && d[temp]<d[idx]+dr[i]){
                    temp++;
                }
                res=min(res,dp(d,temp,c,memo)+c[i]);
            }
            memo[idx]=res;
        }
        return memo[idx];
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        unordered_map<int,int>memo;
        return dp(days,0,costs,memo);
    }
};