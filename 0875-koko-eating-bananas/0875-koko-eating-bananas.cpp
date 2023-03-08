class Solution {
public:
    bool fun(vector<int>& piles, int n, int h, int k){
        long long int m=0;
        for(int i=0;i<n;i++){
            m+=ceil((double)piles[i]/k);
        }
        if(m<=h){
            return true;
        }
        return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int ans=INT_MAX;
        sort(piles.begin(),piles.end());
        int beg=1,end=piles[n-1];
        while(beg<=end){
            int mid=(beg+end)>>1;
            if(fun(piles,n,h,mid)){
                ans=ans<mid?ans:mid;
                end=mid-1;
            }else{
                beg=mid+1;
            }
        }
        return ans;
    }
};