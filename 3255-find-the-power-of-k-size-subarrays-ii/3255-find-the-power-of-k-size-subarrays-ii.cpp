class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n=nums.size(),c=1;
        vector<int>a(n,1),ans(n-k+1,-1);
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]+1){
                c++;
            }else{
                c=1;
            }
            a[i]=c;
        }
        for(int i=k-1,j=0;i<n;i++,j++){
            if(a[i]-k>=0){
                ans[j]=nums[i];
            }
        }
        return ans;
    }
};