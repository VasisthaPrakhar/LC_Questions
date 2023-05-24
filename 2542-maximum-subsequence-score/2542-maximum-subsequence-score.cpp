class Solution {
public:
    typedef long long int ll;
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size();
        vector<pair<int,int>>v(n);
        for(int i=0;i<n;i++){
            v[i].first=nums2[i];
            v[i].second=nums1[i];
        }
        sort(v.begin(),v.end(),greater<pair<int,int>>());
        ll sum=0,ans=-1;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=0;i<k-1;i++){
            pq.push({v[i].second,v[i].first});
            sum+=v[i].second;
        }
        for(int i=k-1;i<n;i++){
            pq.push({v[i].second,v[i].first});
            sum+=v[i].second;
            if(pq.size()>k){
                sum-=pq.top().first;
                pq.pop();
            }
            ans=max(ans,sum*(ll)v[i].first);
        }
        return ans;
    }
};