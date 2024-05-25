class Solution {
private: int mp[11][11];
public:
    typedef long long int ll;
    long long sumDigitDifferences(vector<int>& nums) {
        int n=nums.size();
        memset(mp,0,sizeof(mp));
        for(int i=0;i<n;i++){
            int num=nums[i],j=0;
            while(num){
                int r=num%10;
                mp[j++][r]++;
                num/=10;
            }
        }
        ll ans=0;
        for(int i=0;i<11;i++){
            int k=n;
            for(int j=0;j<11;j++){
                //cout<<mp[i][j]<<" ";
                //int c=0;
                if(mp[i][j]>0){
                    ans+=(k-mp[i][j])*mp[i][j];
                    k-=mp[i][j];
                }
                //ans+=c;
            }
            //cout<<endl;
        }
        return ans;
    }
};