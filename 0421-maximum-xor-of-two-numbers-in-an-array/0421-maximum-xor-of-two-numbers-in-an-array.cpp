class Solution {
public:
    typedef long long int ll;
    int findMaximumXOR(vector<int>& nums) {
       ll mask=0, ans=0;
       unordered_set<ll>s;
       for(int i=30;i>=0;i--){
           mask|=(1<<i);
           ll t=ans|(1<<i);
           for(auto x:nums){
               if(s.find(t^(x & mask))!=s.end()){
                   ans=t;
                   break;
               }
               s.insert(mask & x);
           }
           s.clear();
       }
       return ans;
    }
};