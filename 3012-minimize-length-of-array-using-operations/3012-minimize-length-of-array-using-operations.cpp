class Solution {
public:
    bool check(map<int,int>&m, int n, int a) {
        for(auto x:m){
            if(x.first%a!=0){
                return true;
            }
        }
        return false;
    }
    int minimumArrayLength(vector<int>& nums) {
        int n=nums.size();
        map<int,int>m;
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        auto it=*m.begin();
        if(check(m,n,it.first)){
            return 1;
        }
        return ceil((double)it.second/(double)2);
    }
};