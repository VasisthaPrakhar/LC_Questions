class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        map<int,int>m;
        for(auto x:nums){
            m[x]++;
        }
        int c=0,c1=0;
        for(auto x:m){
            int z=x.second;
            if(z==1){
                return -1;
            }
            if(z%3==0){
                c1+=(z/3);
            }else if(z%3==1){
                c1+=(z/3)-1;
                c+=2;
            }else{
                c1+=(z/3);
                c+=1;
            }
        }
        return c1+c;
    }
};