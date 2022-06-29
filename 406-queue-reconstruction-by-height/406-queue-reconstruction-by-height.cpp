class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& pe) {
        sort(pe.begin(),pe.end(),[](vector<int>&a,vector<int>&b)->bool{
            if(a[0]!=b[0]){
                return a[0]>b[0];
            }else{
                return a[1]<b[1];
            }
        });
        vector<vector<int>>res;
         for (auto& p : pe) 
            res.insert(res.begin() + p[1], p);
        return res;
        //return pe;
    }
};