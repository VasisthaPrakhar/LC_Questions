class Solution {
public:
    void fun(int n,map<int,int>&m){
        for(int i=0;i<32;i++){
            if((n>>i) & 1){
                m[i]++;
            }
        }
    }
    void fun1(int n,map<int,int>&m){
        for(int i=0;i<32;i++){
            if((n>>i) & 1){
                m[i]--;
                if(m[i]==0){
                    m.erase(i);
                }
            }
        }
    }
    int fun2(map<int,int>&m){
        int ans=0;
        for(auto &x:m){
            ans|=(1<<x.first);
        }
        return ans;
    }
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        int j=0,i=0,ans=INT_MAX;
        map<int,int>m;
        while(j<n){
            fun(nums[j],m);
            while(i<=j && fun2(m)>=k){
                fun1(nums[i],m);
                ans=min(ans,j-i+1);
                i++;
            }
            j++;
        }
        return ans==INT_MAX?-1:ans;
    }
};