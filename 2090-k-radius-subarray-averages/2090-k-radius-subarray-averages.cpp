class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>ans;
        long long int sum=0,f=1;
        for(int i=0;i<n;i++){
            if(i-k<0 || i+k>n-1){
                ans.push_back(-1);
            }
            else{
                if(f){
                    sum+=nums[i];
                    int p=i-1,q=i+1;
                    while(p>=i-k && q<=i+k){
                        sum+=nums[p]+nums[q];
                        p--;
                        q++;
                    }
                    f--;
                }else{
                    sum+=nums[i+k];
                    sum-=nums[i-k-1];
                }
                ans.push_back(sum/(2*k+1));
            }
        }
        return ans;
    }
};
static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();