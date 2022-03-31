class Solution {
public:
    bool check(vector<int> num,int n,int s,int m){
        int x=0,l=0;
        int res=INT_MAX;
        for(int r=0;r<n;r++){
            x+=num[r];
            if(x>s){
                x=num[r];
                l++;
            }
            //cout<<l<<" "<<r;
             // if(x==s){
             //    
             // }
            // res=res<(r-l+1)?res:(r-l+1);
        }
       // cout<<endl;
       if(m<(l+1))
       {return false;}
        return true;        
    }
    int splitArray(vector<int>& nums, int m) {
        int sum=0,ans=INT_MAX;
        for(auto x:nums)
        {sum+=x;}
        int ma=*max_element(nums.begin(),nums.end());
        int beg=ma,end=sum;
        while(beg<=end){
            int mid=(beg+end)>>1;
            if(check(nums,nums.size(),mid,m)){
                ans=ans<mid?ans:mid;
                end=mid-1;
            }
            else{
                beg=mid+1;
            }
        }
        return ans;
    }
};