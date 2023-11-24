class Solution {
public:
    typedef long long int ll;
    int findMaximumXOR(vector<int>& nums) {
       ll mask=0, ans=0;
       unordered_set<ll>s;
       for(int i=31;i>=0;i--){
           mask|=(1<<i);
           for(auto x:nums){
               //if(mask & x)
                s.insert(mask & x);
           }
           //if(s.size()==0){continue;}
           ll t=ans|(1<<i);
           for(auto x:s){
               if(s.find(t^x)!=s.end()){
                   ans=t;
                   break;
               }
           }
           s.clear();
       }
       return ans;
    }
};