class Solution {
public:
    bool isPossible(vector<int>& nums) {
      int n=nums.size();
      unordered_map<int,int>m;
      for(auto x:nums){
        m[x]++;
      }
      int j=0;
      while(j<n){
        if(m[nums[j]]==0){
          j++;
          continue;
        }
        int freq=m[nums[j]],curr=nums[j],cnt=0;
        while(m.find(curr)!=m.end() && m[curr]>=freq){
          freq=max(freq,m[curr]);
          m[curr]--;
          curr++;
          cnt++;
        }
        if(cnt<3){
          return false;
        }
        j++;
      }
      return true;
    }
};