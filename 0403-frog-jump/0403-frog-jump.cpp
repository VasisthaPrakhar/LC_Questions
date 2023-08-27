class Solution {
public:
    void fun(map<int,set<int>>&m, int a,int k){
        m[a+k+1].insert(a);
        m[a+k].insert(a);
        m[a+k-1].insert(a);
    }
    bool canCross(vector<int>& a) {
        int n=a.size();
        map<int,set<int>>m;
        if(a[1]-1!=a[0]){
            return false;
        }
        vector<bool>dp(n,false);
        dp[0]=true;
        dp[1]=true;
        fun(m,a[1],1);
        for(int i=2;i<n;i++){
            if(m.find(a[i])!=m.end()){
                dp[i]=true;
                for(auto x:m[a[i]]){
                    fun(m,a[i],a[i]-x);
                }
            }
        }
        // for(auto x:m){
        //     cout<<x.first<<" : ";
        //     for(auto y:x.second){
        //         cout<<y<<" ";
        //     }
        //     cout<<endl;
        // }
       return dp[n-1];
    }
};