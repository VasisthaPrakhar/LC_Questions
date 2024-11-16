class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n=nums.size(),c=1;
        vector<int>a(n,1),ans;
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]+1){
                c++;
            }else{
                c=1;
            }
            a[i]=c;
        }
        for(int i=k-1;i<n;i++){
            if(a[i]-k>=0){
                ans.push_back(nums[i]);
            }else{
                ans.push_back(-1);
            }
        }
        return ans;
    }
};