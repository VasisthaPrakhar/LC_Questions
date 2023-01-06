class Solution {
public:
    int maxIceCream(vector<int>& co, int c) {
        sort(co.begin(),co.end());
        int n=co.size();
        int ans=0;
        for(int i=0;i<n;i++){
            if(c>=co[i]){
                ans++;
                c-=co[i];
            }
        }
        return ans;
    }
};