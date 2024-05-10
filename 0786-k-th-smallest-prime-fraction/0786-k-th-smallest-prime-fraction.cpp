class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n=arr.size();
        vector<vector<double>>a;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                double x=arr[i],y=arr[j];
                vector<double>t;
                t.push_back(x/y);
                t.push_back(x);
                t.push_back(y);
                a.push_back(t);
            }
        }
        sort(a.begin(),a.end());
        return {(int)a[k-1][1],(int)a[k-1][2]};
    }
};