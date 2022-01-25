class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int c=0,n=arr.size();
        bool sign=true;
        if(n<3 || arr[1]<arr[0]){
            return false;
        }
        for(int i=0;i<n-1;i++){
            if(arr[i+1]==arr[i]){
                return false;
            }
            if(sign && arr[i+1]<arr[i]){
                c++;
                sign=!sign;
            }else if(!sign && arr[i+1]>arr[i]){
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
static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();