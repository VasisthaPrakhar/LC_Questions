class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int c=0,n=arr.size();
        bool sign=true;
        if(n<3){
            return false;
        }
        if(arr[1]-arr[0]<0){
            c=1;
        }
        for(int i=0;i<n-1;i++){
            if(arr[i+1]-arr[i]==0){
                return false;
            }
            if(sign && arr[i+1]-arr[i]<0){
                c++;
                sign=!sign;
            }else if(!sign && arr[i+1]-arr[i]>0){
                c++;
                sign=!sign;
            }
        }
        if(c==1){
            return true;
        }
        return false;
    }
};