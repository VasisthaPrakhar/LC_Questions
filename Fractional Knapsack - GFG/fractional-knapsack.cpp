// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        double ans=0;
        priority_queue<pair<double,int>>pq;
        for(int i=0;i<n;i++){
            pq.push({(double)arr[i].value/(double)arr[i].weight,i});
        }
        while(!pq.empty() && W>=0){
            double k=pq.top().first;
            int idx=pq.top().second;
            //cout<<k<<" "<<idx<<" "<<ans<<endl;
            pq.pop();
            if(arr[idx].weight<=W){
                W-=arr[idx].weight;
                ans+=arr[idx].value;
            }else{
                ans+=(double)W*k;
                W=0;
            }
        }
        return ans;
    }
        
};


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends