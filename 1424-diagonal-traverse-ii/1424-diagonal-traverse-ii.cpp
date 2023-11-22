class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        // int n=nums.size(),m=0;
        // for(auto x:nums){
        //     m=max(m,(int)x.size());
        // }
        // vector<int>ans;
        // for(int i=0;i<(n+m)-1;i++){
        //     int k=(i<n)?i:n-1,j=i-k;
        //     while(k>=0 && j<m){
        //         if(k+j==i && j<nums[k].size()){
        //             ans.push_back(nums[k][j]);
        //         }
        //         k--,j++;
        //     }
        // }
        // return ans;
        int n = nums.size();
        queue<pair<int, int>> q;
        vector<int> ans;

        q.push( {0, 0} );
        while (!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            ans.push_back(nums[i][j]);
            if(!j && i + 1 < n) q.push( {i + 1, 0} );
            if(j + 1 < nums[i].size()) q.push( {i, j + 1} );
        }

        return ans;
    }
};