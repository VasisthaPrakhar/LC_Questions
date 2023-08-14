class Solution {
public:
    // int funp(vector<int>& a,int s,int e){
    //     int pivot=a[e];
    //     int i=s-1;
    //     for(int j=s;j<e;j++){
    //         if(a[j]<pivot){
    //             i++;
    //             swap(a[i],a[j]);
    //         }
    //     }
    //     swap(a[i+1],a[e]);
    //     return i+1;
    // }
    // int fun(vector<int>& nums,int s,int e,int p){
    //     int x=funp(nums,s,e);
    //     int k=e-x+1;
    //     if(k==p){
    //         return nums[x];
    //     }
    //     else if(k<p){
    //         return fun(nums,s,x-1,p); 
    //     }else{
    //         return fun(nums,x+1,e,p);
    //     }
    // }
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>pq;
        for(auto &x:nums){
            pq.push(x);
        }
        while(!pq.empty() && k>1){
            k--;
            pq.pop();
        }
        return pq.top();
    }
};