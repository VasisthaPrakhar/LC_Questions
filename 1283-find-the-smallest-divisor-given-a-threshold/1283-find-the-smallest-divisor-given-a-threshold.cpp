class Solution {
public:
    bool check(vector<int>& a, int &t,int mid){
        int ans=0;
        for(auto x:a){
            ans+=ceil((double)x/(double)mid);
        }
        return ans<=t;
    }
    int smallestDivisor(vector<int>& nums, int th) {
        int beg=1,end=1e6,mid;
        while(beg<end){
            mid=(beg+end)>>1;
            if(check(nums,th,mid)){
                end=mid;
            }else{
                beg=mid+1;
            }
        }
        return end;
    }
};