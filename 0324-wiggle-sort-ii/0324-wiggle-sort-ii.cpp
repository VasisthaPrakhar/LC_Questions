class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int sz=n/2;
        if(n%2){sz++;}
        sort(nums.begin(),nums.begin()+sz,greater<int>());
        for(int i=1;i<n-1;i+=2){
            for(int j=n-1;j>i;j--){
                swap(nums[j],nums[j-1]);
            }
        }
        //return nums;
    }
};