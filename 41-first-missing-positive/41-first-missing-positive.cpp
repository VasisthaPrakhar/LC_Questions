class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int>s;
        int ma=0;
        for(auto x:nums){
            if(x>0){
                s.insert(x);
            }
            ma=ma>x?ma:x;
        }
        for(int i=1;i<=ma;i++){
            if(s.find(i)==s.end()){
                return i;
            }
        }
        return ma+1;
    }
};