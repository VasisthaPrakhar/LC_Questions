class Solution {
public:
    int ans=0;
    bool check(unordered_set<int>&st,string &s){
        vector<int>a(26,0);
        for(auto x:s){
           a[x-'a']++;
           if(a[x-'a']>1){
               return false;
           }
        }
        for(auto x:s){
            if(st.find(x)!=st.end()){
                return false;
            }
        }
        return true;
    }
    void fun(vector<string>& arr,int n,int idx,int len,unordered_set<int> &k){
        if(idx==n){
            ans=max(ans,len);
            return;
        }
        if(check(k,arr[idx])){
            int c=0;
            for(auto x:arr[idx]){
                k.insert(x);
            }
            fun(arr,n,idx+1,len+arr[idx].length(),k);
            for(auto x:arr[idx]){
                k.erase(x);
            }
        }
        fun(arr,n,idx+1,len,k);
    }
    int maxLength(vector<string>& arr) {
        int n=arr.size();
        ans=0;
        unordered_set<int>st;
        fun(arr,n,0,0,st);
        return ans;
    }
};