static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();
class Solution {
public:
    bool canReach(string s, int mi, int ma) {
        int n=s.length();
        if(s[n-1]!='0'){
            return false;
        }
        vector<int>a;
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                a.push_back(i);
            }
        }
        int n1=a.size();
        vector<int>vis(n1,0);
        queue<int>q;
        q.push(0);
        vis[0]=1;
        int k=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            if(node==n-1){
                return true;
            }
            int f=node+mi;
            if(f<k){
                f=k;
            }
            auto low=lower_bound(a.begin(),a.end(),f)-a.begin();
            for(int i=low;i<n1 && a[i]<=min(node+ma,n-1);i++){
                if(!vis[i]){
                    q.push(a[i]);
                    vis[i]=1;
                }
            }
            k=min(node+ma+1,n-1);
        }
        return false;
    }
};