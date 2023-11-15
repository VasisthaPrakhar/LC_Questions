class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++){
            if(i==0){
                if(arr[i]>1){
                    arr[i]=1;
                }
            }else{
                if(arr[i]>arr[i-1]){
                    arr[i]=arr[i-1]+1;
                }else{
                    arr[i]=arr[i-1];
                }
            }
        }
        return arr[n-1];
    }
};