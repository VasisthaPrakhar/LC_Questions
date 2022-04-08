class Solution {
public:
    int largestPerimeter(vector<int>& a) {
        int n=a.size(),ans=0;
        sort(a.begin(),a.end());
        for(int i=n-1;i>=2;i--){
            if(a[i]<a[i-1]+a[i-2]){
                ans=a[i]+a[i-1]+a[i-2];
                break;
            }
        }
        return ans;
    }
};