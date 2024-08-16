class Solution {
public:
    int maxDistance(vector<vector<int>>& arr) {
        int n=arr.size();
        map<int,int>mi;
        map<int,int,greater<int>>ma;
        for(int i=0;i<n;i++){
            mi[arr[i][0]]++;
            ma[arr[i].back()]++;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int a=arr[i][0],b=arr[i].back();
            mi[a]--;
            if(mi[a]==0){
                mi.erase(a);
            }
            ma[b]--;
            if(ma[b]==0){
                ma.erase(b);
            }
            ans=max({ans,abs(b-mi.begin()->first),(ma.begin()->first-a)});
            mi[a]++,ma[b]++;
        }
        return ans;
    }
};