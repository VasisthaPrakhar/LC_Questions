class Solution {
public:
        int ans=0;
    int check(vector<int>adj[],int next,int n){
       int k= min(next+6,n*n)-next;
           if(k==adj[next].size()){
               return 0;
           }
        else{
            return adj[next].back();
        }
    }
      void bfs(int i,vector<int>&vis,vector<int>adj[],int n){
        int dest;
        queue<int>q;
        q.push(i);
          vis[i]=1;
          int res=0;
        while(!q.empty()){
            int k=q.size();
            while(k-->0){
                int node=q.front();
                if(node==n*n){
                 //   cout<<res<<" ";
                 //   res=0;
                    ans=res;
                    return;
                }
                q.pop();
                //cout<<res;
                // for(auto x: adj[node]){
                //     int f=0;                    
                //     for(auto y: adj[x]){
                //         int ma=min(x+6,n*n);
                //         if(y>ma || y<node){
                //             dest=y;
                //             f=1;
                //         }
                //     }
                //     if(f!=1){
                //         dest=x;
                //     }
                //     if(!vis[dest]){
                //         //cout<<dest<<" ";
                //         q.push(dest);
                //         vis[dest]=1;
                //     }
                // }
                 for(int next=node+1;next<=min(node+6,n*n);next++){    //check boundaries
                    if(check(adj,next,n)){
                        dest=check(adj,next,n);
                    }
                    else{
                        dest=next;
                    }
                    if(!vis[dest]){     //for bfs push only if not visited
                        q.push(dest);
                        vis[dest]=1;
                    }
                }
            }
            res++;
           // cout<<endl;
        }
       // return;
     }
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        int r=n-1,c=0,flag=0,f=0,f1=0;
        vector<int>adj[(n*n)+1];
        for(int i=1;i<=n*n;i++){
            int ma=min(i+6,n*n);
            for(int j=i+1;j<=n*n&&j<=ma;j++){
               adj[i].push_back(j); 
            }
            if(r>=0 && c>=0 && c<n && r<n && board[r][c]>0)
            adj[i].push_back(board[r][c]);
            int flagr=flag;
            if(f==1){
                r--;
                f--;
            }
            if(f1==1){
                c--;
                f1--;
            }
            if(flag%2==0){
                c++;
                if(c==n-1){
                    flag++;
                }
            }
            else{
                f1=1;
                if(c==0){
                    flag++;
                }
            }
            if(flag>flagr){
                f=1;
            }
            
        }
        vector<int>vis((n*n)+1,0);
        bfs(1,vis,adj,n);
        // if(ans>1){
        //     return ans-1;
        // }
        // for(auto x:adj){
        //     for(auto x1:x){
        //         cout<<x1<<" ";
        //     }
        //     cout<<endl;
        // }
        if(ans==0){
            return -1;
        }
        return ans;
    }
};