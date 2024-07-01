class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n=arr.size();
        for(int i=0;i<n;i++){
            if(arr[i]%2){
                int c=0;
                while(i<n && arr[i]%2){
                    i++,c++;
                }
                i--;
                if(c>=3){
                    return true;
                }
            }
        }
        return false;
    }
};