class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int>ans;
        for(auto n:nums){
            if(n%2==0){
                ans.push_back(-1);
            }else{
                if((n&(n+1))==0){
                    ans.push_back(n>>1);
                }else{
                    int k=1,pos=-1,num=n;
                    while(n&1){
                        pos++;
                        n=n>>1;
                    }
                    k=k<<pos;
                    ans.push_back(num^k);
                }
            }
        }
        return ans;
    }
};