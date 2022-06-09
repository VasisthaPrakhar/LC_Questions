class Solution {
public:
    vector<int> twoSum(vector<int>& num, int t) {
        int n=num.size();
        for(int i=0;i<n;i++){
            int k=t-num[i];
            int idx=lower_bound(num.begin()+i+1,num.end(),k)-num.begin();
            if(idx<n && num[idx]==k){
                return {i+1,idx+1};
            }
        }
        return {-1,-1};
    }
};