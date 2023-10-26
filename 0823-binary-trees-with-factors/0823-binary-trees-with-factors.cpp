#pragma GCC optimize("O3")
class Solution {
public:
    const int mod=1e9+7;
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n=arr.size();
        sort(arr.begin(), arr.end());
        vector<pair<int, long long>> A(n);
        long long ans=0;
        for(int i=0; i<n; i++){
            int x=arr[i];
            A[i]={x, 1};
            int sqrt_x=sqrt(x);

            #pragma unroll
            for(int j=0; A[j].first<=sqrt_x; j++){
                auto& [y, count]=A[j];
                if (x%y == 0){
                    int z=x/y;
                    if (z==y){
                        A[i].second=(A[i].second+count*count)% mod;
                    }
                    else{
                        int idx=lower_bound(arr.begin()+j, arr.end(), z)    
                        -arr.begin();
                        if (idx<n && arr[idx]==z)
                            A[i].second=(A[i].second+count*A[idx].second*2)% mod;
                    }

                }
            }
            ans =(ans+ A[i].second)%mod;
        }
        return ans;
    }
};