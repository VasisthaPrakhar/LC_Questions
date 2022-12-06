class Solution {
public:
    vector<int> decode(vector<int>& enc) {
        int n=enc.size()+1;
        vector<int>ans(n);
        int k=0,tot=0;
        for(int i=1;i<=n;i++){
            tot^=i;
        }
        k^=tot;
        for(int i=0;i<n-1;i++){
            if(i%2){
                k^=enc[i];
            }
        }
        ans[0]=k;
        for(int i=1;i<n;i++){
            ans[i]=ans[i-1]^enc[i-1];
        }
        return ans;
    }
};