class Solution {
    vector<int>og;
public:
    Solution(vector<int>& nums) {
        og=nums;
    }
    
    vector<int> reset() {
        return og;
    }
    
    vector<int> shuffle() {
        vector<int>temp=og;
        int n=og.size();
        //srand(time(0));
        for(int i=0;i<n;i++){
            swap(temp[i],temp[(rand()%(n))]);
        }
        return temp;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */