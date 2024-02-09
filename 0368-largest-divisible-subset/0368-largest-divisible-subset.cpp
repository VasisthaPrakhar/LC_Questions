static const auto Initialize = []{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int n;
    unordered_map<int,vector<int>>m;
    vector<int> fun(vector<int>& nums, int beg){
        if(beg>=n){
            return {};
        }
        if(m.count(beg)){
            return m[beg];
        }
        for(int i=beg+1;i<n;i++){
            if(nums[i]%nums[beg]!=0){
                continue;
            }
            vector<int>ma=fun(nums,i);
            if(ma.size()>m[beg].size()){
                m[beg]=ma;
            }
        }
        m[beg].push_back(nums[beg]);
        return m[beg];
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        // n=nums.size();
        // sort(nums.begin(),nums.end());
        // vector<int>ans;
        // for(int i=0;i<n;i++){
        //     vector<int>ma=fun(nums,i);
        //     if(ma.size()>ans.size()){
        //         ans=ma;
        //     }
        // }
        // return ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>ans;
        map<int,set<int>>m;
        for(int i=0;i<n;i++){
            m[i].insert(nums[i]);
        }
        for(int i=n-1;i>=0;i--){
            for(int j=i+1;j<n;j++){
                if(nums[j]%nums[i]==0){
                    if(m[i].size() < m[j].size()+1){
                        m[i].clear();
                        m[i].insert(nums[i]);
                        for(auto x:m[j]){
                            m[i].insert(x);
                        }
                    }
                }
            }
        }
        for(auto x:m){
            //cout<<x.first<<": ";
            if(x.second.size()>ans.size()){
                vector<int>a;
                for(auto y:x.second){
                    a.push_back(y);
                }
                ans=a;
            }
            //cout<<endl;
        }
        return ans;
    }
};