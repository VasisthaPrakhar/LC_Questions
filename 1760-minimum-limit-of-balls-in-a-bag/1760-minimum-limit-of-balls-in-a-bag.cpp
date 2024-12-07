class Solution {
public:
    typedef long long int ll;
    bool fun(vector<int>&a,int k, int m){
        double c=0;
        for(auto x:a){
            double z=ceil((double)x/(double)k);
            c+=(z-1);
        }
        return c<=m;
    }
    int minimumSize(vector<int>& nums, int mo) {
        int n=nums.size();
        ll beg=1,end=*max_element(nums.begin(),nums.end()),mid;
        while(beg<end){
            mid=(beg+end)/2;
            if(fun(nums,mid,mo)){
                end=mid;
            }else{
                beg=mid+1;
            }
        }
        return end;
    }
};