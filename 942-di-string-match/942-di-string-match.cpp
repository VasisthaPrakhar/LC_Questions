static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();
class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n=s.size();
        vector<int>a(n+1);
        for(int i=0;i<=n;i++){
            a[i]=i;
        }
        for(int i=0;i<n;i++){
            int k=i,h=i;
            while(s[k]=='D'){
                k++;
            }
            for(int j=k;j>=h;j--){
                a[i++]=j;
            }
            i--;
        }
        return a;
    }
};