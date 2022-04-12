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
        int ma=*max_element(nums.begin(),nums.end());
        int beg=1,end=ma,mid;
        while(beg<end){
            mid=(beg+end)>>1;
            if(check(nums,th,mid)){
                end=mid;
            }else{
                beg=mid+1;
            }
        }
        return beg;
    }
};