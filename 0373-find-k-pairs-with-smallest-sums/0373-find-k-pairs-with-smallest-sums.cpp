// class Solution {
// public:
//     typedef long long int ll;
//     vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
//         vector<vector<int>>ans;
//         int n=nums1.size();
//         int m=nums2.size();
//         priority_queue<pair<ll,pair<int,int>>>pq;
//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 ll sum=nums1[i]+nums2[j];
//                 if(pq.size()<k){
//                     pq.push({sum,{nums1[i],nums2[j]}});
//                 }else if(sum<pq.top().first){
//                     pq.pop();
//                     pq.push({sum,{nums1[i],nums2[j]}});
//                 }else{
//                     break;
//                 }
//             }
//         }
//         while(!pq.empty()){
//             ans.push_back({pq.top().second.first,pq.top().second.second});
//             pq.pop();
//         }
//         reverse(ans.begin(),ans.end());
//         return ans;
//     }
// };
const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

class Solution
{
public:
	std::vector<std::vector<int>> kSmallestPairs(std::vector<int>& nums1, std::vector<int>& nums2, int k)
	{
		if (nums1.empty() || nums2.empty() || k <= 0) {
            return {};
        }
		auto comp = [&nums1, &nums2](auto const &lhs, auto const &rhs)
		{
            auto &[li, lj] = lhs;
            auto &[ri, rj] = rhs;
			return nums1[li] + nums2[lj] > nums1[ri] + nums2[rj];
		};
		priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> heap(comp);
		heap.emplace(0, 0);
		
		vector<vector<int>> result;
		while (k-- && heap.size()) {
			auto [i, j] = heap.top();
			heap.pop();
			result.push_back({nums1[i], nums2[j]});
			if (i+1 < nums1.size()) {
				heap.emplace(i+1, j);
			}
			if (i == 0 && j + 1 < nums2.size()) {
				heap.emplace(i, j+1);
			}
		}
		return result;
	}
};