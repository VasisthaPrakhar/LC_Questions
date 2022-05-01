class Solution {
public:
    void merge(vector<int>& a, int m, vector<int>& b, int n) {
        int i=0,j=0,k=0;
        vector<int>a1=a;
        while(i<m && j<n){
            if(a1[i]<=b[j]){
                a[k++]=a1[i++];
            }else{
                a[k++]=b[j++];
            }
        }
        while(i<m){
            a[k++]=a1[i++];
        }
        while(j<n){
            a[k++]=b[j++];
        }
    }
};