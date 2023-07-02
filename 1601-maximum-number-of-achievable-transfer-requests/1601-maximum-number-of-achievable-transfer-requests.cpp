class Solution {
public:
    int ans;
    void fun(vector<vector<int>>& arr,int n,int idx,int k,vector<int>&a){
        if(idx>=n){
            int f=0;
            for(auto x:a){
                if(x!=0){
                    f=1;
                    break;
                }
            }
            if(!f){
                ans=max(ans,k);
            }
            return;
        }
        a[arr[idx][1]]++;
        a[arr[idx][0]]--;
        fun(arr,n,idx+1,k+1,a);
        a[arr[idx][1]]--;
        a[arr[idx][0]]++;
        fun(arr,n,idx+1,k,a);
    }
    int maximumRequests(int n, vector<vector<int>>& arr) {
        vector<int>a(n,0);
        ans=0;
        fun(arr,(int)arr.size(),0,0,a);
        return ans;
    }
};