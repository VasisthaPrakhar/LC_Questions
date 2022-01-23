class Solution {
public:
    int numberOfArrays(vector<int>& dif, int lower, int upper) {
        long long int sum=0;
        int n=dif.size(),mi=INT_MAX,ma=INT_MIN;
        for(int i=0;i<n;i++){
            sum+=dif[i];
            ma=sum>ma?sum:ma;
            mi=sum<mi?sum:mi;
        }
        int k,ans;
        if(mi>=0){
            k=lower;
        }else{
            k=lower+abs(mi);
        }
        int res=k>k+ma?k:k+ma;
        ans=(upper-res)<0?0:(upper-res)+1;
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