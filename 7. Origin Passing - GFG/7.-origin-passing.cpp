// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    bool pass_origin(int x1, string Y1, int x2, string Y2){
        // code here
        int y1=0,y2=0,j=0;
        for(int i=Y1.length()-1;i>=0;i--,j++){
            y1+=((Y1[i]-'A')+1)*pow(26,j);
        }
        j=0;
        for(int i=Y2.length()-1;i>=0;i--,j++){
            y2+=((Y2[i]-'A')+1)*pow(26,j);
        }
        if(x1==x2 && y1==y2){
            return true;
        }
        if(x2-x1==0){
            if(x2==0){
                return true;
            }else{
                return false;
            }
        }
        //cout<<y1<<" "<<y2<<" ";
        //cout<<x2-x1<<" "<<y2-y1<<" ";
        double m=(double)(y2-y1)/(double)(x2-x1);
        //cout<<m<<" ";
        if(m==0.0){
            if(y1==0 || y2==0)
                return true;
            else{
                   return false; 
                }
        }else{
            if(m*x2==(double)y2 || m*x1==(double)y1){
                return true;
            }
            return false;
        }
    }
};


// { Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int X1, X2;
        cin >> X1 >> X2;
        string Y1, Y2;
        cin >> Y1 >> Y2;
        Solution obj;
        if(obj.pass_origin(X1, Y1, X2, Y2)){
            cout << "1\n";
        }
        else{
            cout << "0\n";
        }
    }
}  // } Driver Code Ends