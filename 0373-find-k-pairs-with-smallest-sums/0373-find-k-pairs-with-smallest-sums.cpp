class Solution {
public:
    typedef long long int ll;
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>>ans;
        int n=nums1.size();
        int m=nums2.size();
        priority_queue<pair<ll,pair<int,int>>>pq;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ll sum=nums1[i]+nums2[j];
                if(pq.size()<k){
                    pq.push({sum,{nums1[i],nums2[j]}});
                }else if(sum<pq.top().first){
                    pq.pop();
                    pq.push({sum,{nums1[i],nums2[j]}});
                }else{
                    break;
                }
            }
        }
        while(!pq.empty()){
            ans.push_back({pq.top().second.first,pq.top().second.second});
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
