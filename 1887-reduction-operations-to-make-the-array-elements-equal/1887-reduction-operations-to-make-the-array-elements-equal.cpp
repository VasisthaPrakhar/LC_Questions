class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int n=nums.size();
        map<int,int>m;
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        int ans=0,c=1;
        for(auto it=m.begin();it!=m.end();it++){
            if(it!=m.begin()){
                ans+=c*it->second;
                c++;
            }
        }
        return ans;
    }
};