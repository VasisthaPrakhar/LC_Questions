class Solution {
public:
    int minNumberOfHours(int ir, int ie, vector<int>& en, vector<int>& ex) {
        int n=ex.size();
        int sum=accumulate(en.begin(),en.end(),0);
        int ans=0;
        if(sum>=ir){
            ans=sum-ir+1;
        }
        for(auto x:ex){
            if(x>=ie){
                int temp=x-ie+1;
                ans+=temp;
                ie+=temp+x;
            }else{
                ie+=x;
            }
        }
        return ans;
    }
};