class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& a, int k) {
        int n=a.size(),j=k;
        deque<int>q;
        for(int i=0;i<k;i++){
            while(!q.empty() && a[q.back()]<a[i]){
                q.pop_back();
            }
            q.push_back(i);
        }
        vector<int>ans;
        ans.push_back(a[q.front()]);
        while(j<n){
            if(!q.empty() && q.front()+k==j){
                q.pop_front();
            }
            while(!q.empty() && a[q.back()]<a[j]){
                q.pop_back();
            }
            q.push_back(j);
            ans.push_back(a[q.front()]);
            j++;
        }
        return ans;
    }
};