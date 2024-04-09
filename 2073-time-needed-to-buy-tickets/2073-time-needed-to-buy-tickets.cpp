class Solution {
public:
    int timeRequiredToBuy(vector<int>& t, int k) {
        int n=t.size();
        int ans=0,i=0;
        while(t[k]>0){
            if(t[i]==0){
                i=(i+1)%n;
                continue;
            }
            t[i]--;
            ans++;
            i=(i+1)%n;;
        }
        return ans;
    }
};