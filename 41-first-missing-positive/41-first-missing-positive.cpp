class Solution {
public:
    int firstMissingPositive(vector<int>& A) {
        int n=A.size();
        for(auto &x:A){
            if(x<=0){
                x=n+1;
            }
        }
        for(int i=0;i<n;i++){
            if(abs(A[i])<=n && A[abs(A[i])-1]>0){
                A[abs(A[i])-1]*=-1;   
            }
        }
        for(int i=0;i<n;i++){
            //cout<<nums[i]<<" ";
            if(A[i]>0){
                return i+1;
            }
        }
        return n+1;
    }
};