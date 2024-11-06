class Solution {
public:
    int fun(int n){
        return __builtin_popcount(n);
    }
    bool canSortArray(vector<int>& nums) {
        int n=nums.size();
        // stack<int>s,s1;
        // for(int i=0;i<n;i++){
        //     while(!s.empty() && s.top()>nums[i] && fun(s.top())==fun(nums[i])){
        //         s1.push(s.top());
        //         s.pop();
        //     }
        //     s.push(nums[i]);
        //     while(!s1.empty()){
        //         s.push(s1.top());
        //         s1.pop();
        //     }
        // }
        // vector<int>a;
        // while(!s.empty()){
        //     a.push_back(s.top());
        //     s.pop();
        // }
        // for(int i=0;i<n-1;i++){
        //     if(a[i]<a[i+1]){
        //         return false;
        //     }
        // }
        // return true;
        // for(auto x:nums){
        //     cout<<fun(x)<<" ";
        // }
        int j=0,ma=0,mi=INT_MAX,prev=-1;
        while(j<n){
            ma=nums[j];
            mi=nums[j];
            while(j<n-1 && fun(nums[j])==fun(nums[j+1])){
                ma=max({ma,nums[j],nums[j+1]});
                mi=min({mi,nums[j],nums[j+1]});
                j++;
            }
            //cout<<mi<<" "<<prev<<endl;
            if(mi<=prev){
                return false;
            }
            prev=ma;
            j++;
        }
        return true;
    }
};