class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i=0;
        do{
            i++;
            //cout<<nums[0]<<" "<<nums[1]<<" "<<nums[2]<<endl;
        }while(next_permutation(nums.begin(),nums.end())&& i<1);
    }
};