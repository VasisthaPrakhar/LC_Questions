class Solution {
public:
    int numRescueBoats(vector<int>& p, int lim) {
        int n=p.size();
        sort(p.begin(),p.end());
        int j=n-1,i=0,ans=0;
        while(i<=j){
            if(p[j]+p[i]<=lim){
                i++;
                j--;
            }else{
                j--;
            }
            ans++;
        }
        return ans;
    }
};