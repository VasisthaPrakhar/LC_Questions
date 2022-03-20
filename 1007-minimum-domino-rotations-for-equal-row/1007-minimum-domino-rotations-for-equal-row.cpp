class Solution {
public:
    int solve(int &it, vector<int>& t, vector<int>& b, int &n){
        int ans1=0,ans2=0;
        for(int i=0;i<n;i++){
            if(t[i]!=it && b[i]!=it){
                return INT_MAX;
            }
            else if(t[i]!=it && b[i]==it){
                ans1++;
            }
            else if(t[i]==it && b[i]!=it){
                ans2++;
            }
        }
        return ans1<ans2?ans1:ans2;
    }
    int minDominoRotations(vector<int>& t, vector<int>& b) {
        int n=t.size();
        int ans=INT_MAX;
        for(int i=1;i<=6;i++){
            int temp=solve(i,t,b,n);
            ans=temp<ans?temp:ans;
        }
        return ans==INT_MAX?-1:ans;
    }
};