class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // int i=0;
        // do{
        //     i++;
        // }while(next_permutation(nums.begin(),nums.end())&& i<1);
        next_permutation(nums.begin(),nums.end());
    }
};