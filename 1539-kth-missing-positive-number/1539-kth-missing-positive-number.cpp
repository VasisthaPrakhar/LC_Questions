class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>a;
        int j=0;
        for(int i=1;i<=2000;i++){
            if(j<n && i==arr[j]){
                j++;
            }else{
                a.push_back(i);
            }
        }
        return a[k-1];
    }
};