class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        int c=0,ans=0;
        unordered_map<int,int>m;
        m[0]=-1;
        for(int j=0;j<n;j++){
            if(nums[j]==0){
                c++;
            }else{
                c--;
            }
            if(m.find(c)!=m.end()){
                ans=ans>j-m[c]?ans:j-m[c];
            }else{
                m[c]=j;
            }
        }
        return ans;
    }
};