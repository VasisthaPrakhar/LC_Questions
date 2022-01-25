class Solution {
public:
    // void fun(vector<vector<int>>&ans,vector<int>& a,vector<int>& b,int i){
    //     if(i>=a.size()){
    //         ans.push_back(b);
    //         return;
    //     }
    //     fun(ans,a,b,i+1);
    //     b.push_back(a[i]);
    //     fun(ans,a,b,i+1);
    //     b.pop_back();
    // }
    vector<vector<int>> subsets(vector<int>& a) {
        int n=a.size();
        int lim=pow(2,n);
        vector<vector<int>>ans;
        for(int i=0;i<lim;i++){
            vector<int>b;
            for(int j=0;j<n;j++){
                if(i&(1<<j)){
                    b.push_back(a[j]);
                }
            }
            ans.push_back(b);
        }
        return ans;
    }
};