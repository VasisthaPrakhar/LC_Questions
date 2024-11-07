class Solution {
public:
    int largestCombination(vector<int>& c) {
        vector<int>bits(32,0);
        for(auto x:c){
            for(int i=0;i<32;i++){
                if(1<<i & x){
                    bits[i]++;
                }
            }
        }
        return *max_element(bits.begin(),bits.end());
    }
};