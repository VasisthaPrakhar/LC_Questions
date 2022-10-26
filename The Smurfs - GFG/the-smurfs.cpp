//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
void fun(char a,char b,char c,map<char,int>&m1){
   m1[a]+=m1[c];
   m1[b]-=m1[c];
   m1.erase(c);
}
class Solution{
public:
    int findMin(int n, char a[]){
        // code here
        // map<char,map<char,int>>m;
        // m['R']['G']='B';
        // m['G']['R']='B';
        // m['R']['B']='G';
        // m['B']['R']='G';
        // m['B']['G']='R';
        // m['G']['B']='R';
        
        map<char,int>m1;
        for(int i=0;i<n;i++){
            m1[a[i]]++;
        }
        int ans=0;
        if(m1.size()>2){
            if(m1['R']>=m1['G'] && m1['B']>=m1['G']){
                fun('R','B','G',m1);
            }else if(m1['G']>=m1['R'] && m1['B']>=m1['R']){
                fun('G','B','R',m1);
            }else if(m1['G']>=m1['B'] && m1['R']>=m1['B']){
                fun('G','R','B',m1);
            }
        }
        if(m1.size()==2){
            int p,q;
            auto it=m1.begin();
            auto it1=it;
            it++;
            p=it1->second,q=it->second;
            if(p%2==0 && q%2==0){
                ans=2;
            }else{
                ans=1;
            }
        }else{
            ans=m1.begin()->second;
        }
        // if(m1['R']==m1['G'] && m1['R']==m1['B']){
        //     m1['R']++;
        //     m1['G']--;
        //     m1['B']--;
        // }
        // int f=0;
        // while(m1.size()>1){
        //     if(m1['R']>=m1['G'] && m1['B']>=m1['G']){
        //         fun('R','B','G',m1);
        //     }else if(m1['G']>=m1['R'] && m1['B']>=m1['R']){
        //         fun('G','B','R',m1);
        //     }else if(m1['G']>=m1['B'] && m1['R']>=m1['B']){
        //         fun('G','R','B',m1);
        //     }else{
        //         f=1;
        //         break;
        //     }
        //     if(m1['R']==0){
        //         m1.erase('R');
        //     }
        //     if(m1['B']==0){
        //         m1.erase('B');
        //     }
        //     if(m1['G']==0){
        //         m1.erase('G');
        //     }
        // }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        char a[n];
        for(int i = 0;i < n;i++)
            cin>>a[i];
        
        Solution ob;
        cout<<ob.findMin(n, a)<<"\n";
    }
    return 0;
}
// } Driver Code Ends