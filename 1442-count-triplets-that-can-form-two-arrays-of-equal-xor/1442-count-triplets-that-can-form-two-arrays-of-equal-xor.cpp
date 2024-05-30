class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n=arr.size(),ans=0;
        for(int i=1;i<n;i++){
            int k=0;
            map<int,int>mp;
            for(int j=i;j<n;j++){
                k=k^arr[j];
                mp[k]++;
            }
            k=0;
            for(int j=i-1;j>=0;j--){
                k=k^arr[j];
                if(mp.find(k)!=mp.end()){
                    ans+=mp[k];
                }
            }
        }
        return ans;
    }
};