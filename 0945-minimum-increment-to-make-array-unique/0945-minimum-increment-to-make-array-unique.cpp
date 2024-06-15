class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        // set<int>s;
        // for(int i=0;i<100001;i++){s.insert(i);}
        // for(auto x:nums){
        //     if(s.find(x)!=s.end())
        //         s.erase(x);
        // }
        // map<int,int>m;
        // int ans=0,k=100001;
        // for(auto x:nums){
        //     m[x]++;
        //     if(m[x]>1){
        //         auto f=s.lower_bound(x);
        //         if(f==s.end()){
        //             ans+=k-x;
        //             k++;
        //         }else{
        //             ans+=*f-x;
        //             s.erase(f);
        //         }
        //         m[x]--;
        //     }
        // }
        // return ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans=0,c=0;
        for(int i=0;i<n;i++){
            c=max(nums[i],c);
            ans+=c-nums[i];
            c++;
        }
        return ans;
    }
};