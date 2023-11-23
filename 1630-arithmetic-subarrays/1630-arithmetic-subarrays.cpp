class Solution {
public:
    bool check(vector<int>&a,int n){
        if(n==1){return true;}
        int d=a[1]-a[0];
        for(int i=1;i<n;i++){
            if(d!=a[i]-a[i-1]){
                return false;
            }
        }
        return true;
    }
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n=nums.size(),m=l.size();
        vector<bool>ans;
        for(int i=0;i<m;i++){
            vector<int>a;
            for(int j=l[i];j<=r[i];j++){
                a.push_back(nums[j]);
            }
            sort(a.begin(),a.end());
            ans.push_back(check(a,r[i]-l[i]+1));
        }
        return ans;
    }
};