class Solution {
public:
    int longestSubsequence(vector<int>& arr, int d) {
        int n=arr.size(),ans=1;
        unordered_map<int,int>m;
        for(int i=0;i<n;i++){
            if(m.count(arr[i]-d)){
                m[arr[i]]=m[arr[i]-d]+1;
                ans=max(ans,m[arr[i]]);
            }else{
                m[arr[i]]=1;
            }
        }
        return ans;
    }
};