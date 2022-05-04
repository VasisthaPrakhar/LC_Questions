class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n=nums.size();
        map<int,int>m;
        int ans=0;
        for(int i=0;i<n;i++){
            int s=k-nums[i];
            if(m.count(s)){
                ans++;
                m[s]--;
                if(m[s]==0){
                    m.erase(s);
                }
            }else{
                m[nums[i]]++;
            }
        }
        return ans;
    }
};