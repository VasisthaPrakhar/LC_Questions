class Solution {
public:
    int dp(vector<int>& co,int am,unordered_map<int,int> &memo,int &n){
        if(am==0){
            return 0;
        }
        if(!memo.count(am)){
            int mi=INT_MAX;
            for(int i=0;i<n;i++){
                if(am-co[i]>=0){
                    int temp=dp(co,am-co[i],memo,n);
                    if(temp!=-1)
                    mi=min(mi,temp);   
                }
            }
            if(mi==INT_MAX){
                memo[am]=-1;
            }else
                memo[am]=mi+1;
        }
        return memo[am];
    }
    int coinChange(vector<int>& co, int am) {
        if(am==0){
            return 0;
        }
        int n=co.size();
        unordered_map<int,int>memo;
        for(auto x:co){
            if(x<=am){
                memo[x]=1;
            }
        }
        int ans=dp(co,am,memo,n);
        return ans==INT_MAX?-1:ans;
    }
};