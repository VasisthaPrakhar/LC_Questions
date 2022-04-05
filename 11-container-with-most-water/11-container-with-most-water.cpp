class Solution {
public:
    int maxArea(vector<int>& h) {
        int n=h.size();
        int j=n-1,i=0;
        int ans=0;
        while(j>i){
            ans=max(ans,(min(h[i],h[j])*(j-i)));
            if(h[i]<h[j]){
                i++;
            }
            else
            j--;
        }
        return ans;
    }
};