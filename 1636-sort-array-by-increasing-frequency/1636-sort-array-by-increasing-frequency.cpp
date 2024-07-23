class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int,int>m;
        for(auto x:nums){
            m[x]++;
        }
        vector<pair<int,int>>v;
        for(auto x:m){
            v.push_back({x.second,x.first});
        }
        sort(v.begin(),v.end(),[](pair<int,int>&a,pair<int,int>&b)->bool{
            if(a.first==b.first){
                return a.second>b.second;
            }
            return a.first<b.first;
        });
        vector<int>ans;
        for(auto x:v){
            int k=x.first;
            while(k){
                ans.push_back(x.second);
                k--;
            }
        }
        return ans;
    }
};