class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n=arr.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            if(arr[i]<0){
                arr[i]=arr[i]%k;
            }
            mp[(arr[i]+k)%k]++;
        }
        for(int i=0;i<k;i++){
            if(i==0){
                if(mp[i]%2){
                    return false;
                }
            }else if(mp[i]!=mp[k-i]){
                return false;
            }
        }
        return true;
    }
};