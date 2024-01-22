class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        map<int,int>s;
        int n=nums.size();
        for(auto x:nums){
            s[x]++;
        }
        vector<int>v(2,0);
        for(int i=1;i<=n;i++){
            if(s[i]==0){
                v[1]=i;
            }
            if(s[i]==2){
                v[0]=i;
            }
        }
        return v;
    }
};