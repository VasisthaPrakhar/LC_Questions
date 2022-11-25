class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        int mod=1e9 + 7;
        vector<long long int>pre(n),suf(n);
        stack<int>s;
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && arr[s.top()]>=arr[i]){
                s.pop();
            }
            if(s.empty()){
                suf[i]=n;
            }else{
                suf[i]=s.top();
            }
            s.push(i);
        }
        while(!s.empty()){
            s.pop();
        }
        for(int i=0;i<n;i++){
            while(!s.empty() && arr[s.top()]>arr[i]){
                s.pop();
            }
            if(s.empty()){
                pre[i]=-1;
            }else{
                pre[i]=s.top();
            }
            s.push(i);
        }
        long long int ans=0;
        for(int i=0;i<n;i++){
            ans =( ans%mod + ((long long int)arr[i]*(i-pre[i])*(suf[i]-i))%mod);
            //cout<<(i-pre[i])<<" "<<(suf[i]-i)<<endl;
            //cout<<ans<<" ";
        }
        // for(auto x:pre){
        //     cout<<x<<" ";
        // }
        // cout<<ans;
        // cout<<endl;
        return ans%mod;
    }
};