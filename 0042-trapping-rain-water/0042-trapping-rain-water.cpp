static const auto Initialize = []{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int trap(vector<int>& height) {
         int n= height.size();   
        if(n<=2){return 0;}
        vector<int> left(n), right(n);
        int ans=0;
        left[0]=height[0];
        right[n-1]=height[n-1];
        for(int i=1;i<n;i++){
            left[i] = (left[i-1] > height[i]) ? left[i-1] : height[i];
            right[n-i-1] = (right[n-i] > height[n-i-1]) ? right[n-i] : height[n-i-1];
        }
        
        for(int i=0;i<n;i++){
            int mi = left[i]>right[i]?right[i]:left[i];
            ans= ans+(mi-height[i]);
        }
        return ans;
    }
};