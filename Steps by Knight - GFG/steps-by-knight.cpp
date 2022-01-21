// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int dr[8] = {1,1,-1,-1, 2, 2,-2,-2}; 
    int dc[8] = {2,-2,2,-2, -1, 1,-1,1};
    
    int bfs(int r, int c, int rf, int cf,int n,vector<vector<int>>&grid) { 
    queue<pair<int,int>> qu;
    qu.push({r, c});
    int ans=-1;
    while (!qu.empty()) { 
        int s=qu.size();
        ans++;
        while(s--){
            auto current = qu.front();
            qu.pop();
            if(current.first==rf && current.second==cf){
                return ans;
            }
            for (int i = 0; i < 8; i++) { 
                int R = current.first + dr[i]; 
                int C = current.second + dc[i];
    
                if (R < 0 or R >= n or C < 0 or C >= n) continue; 
                if (grid[R][C] == 1) continue;
                grid[R][C] = 1;
    
                qu.push({R, C});
            }

        }
    }
    return ans;
}
	int minStepToReachTarget(vector<int>&K,vector<int>&T,int N)
	{
	    // Code here
	    vector<vector<int>>a(N,vector<int>(N,0));
	   int ans= bfs(K[0]-1,K[1]-1,T[0]-1,T[1]-1,N,a);
	   return ans;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends