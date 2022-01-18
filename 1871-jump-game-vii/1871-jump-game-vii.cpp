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
        vector<int>vis(n,0);
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
            for(int i=max(node+mi,k);i<=min(node+ma,n-1);i++){
                if(!vis[i] && s[i]=='0'){
                    q.push(i);
                    vis[i]=1;
                }
            }
            k=min(node+ma+1,n-1);
        }
        return false;
    }
};
