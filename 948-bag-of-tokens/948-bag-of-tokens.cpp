class Solution {
public:
    int bagOfTokensScore(vector<int>& t, int p) {
        int n=t.size();
        if(n==0){
            return 0;
        }
        int j=n-1,c=0,ans=0;
        sort(t.begin(),t.end());
        for(int i=0;i<n;i++){
            if(p>=t[i]){
                p-=t[i];
                c++;
            }else if(c>0){
                p+=t[j--];
                c--;
                i--;
            }else{
                return ans;
            }
            ans=ans>c?ans:c;
        }
        return ans;
    }
};