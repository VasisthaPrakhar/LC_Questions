class Solution {
public:
    int hIndex(vector<int>& c) {
        int n=c.size();
        sort(c.begin(),c.end());
        for(int i=0;i<n;i++){
            //cout<<c[i]<<" ";
            if(c[i]>=n-i){
                return n-i;
            }
        }
        return 0;
    }
};