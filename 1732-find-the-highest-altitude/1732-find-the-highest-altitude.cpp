class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ma=0,s=0;
        for(auto x:gain){
            s+=x;
            ma=max(ma,s);
        }
        return ma;
    }
};