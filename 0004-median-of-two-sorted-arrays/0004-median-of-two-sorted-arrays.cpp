class Solution {
public:
    double calc(vector<int> v){
        double ans = 0, ce1 = 0, ce2 = 0;
        int n = v.size();
        if(n%2!=0){
            ans = v[n/2];
        }
        else{
            ce1 = v[(n-1)/2];
            ce2 = v[(n+1)/2];
            ans = (ce1 + ce2)/2;
        }
        return ans;
    }
    double findMedianSortedArrays(vector<int>& v1, vector<int>& v2) {
         int i=0,j=0,k=0;
        double ans = 0;
        int n = v1.size(), m = v2.size(); 
            vector<int> c(n+m);
 
         while(i<n || j<m){
             if(j == m || (i < n && v1[i] < v2[j])){
                    c[k++]=v1[i++];
                        }
                else{
                    c[k++]=v2[j++];
                }
            }
            ans = calc(c);
            return ans;
            }
};