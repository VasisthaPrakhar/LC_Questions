class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n=arr.size();
        int ma=*max_element(arr.begin(),arr.end());
        if(k>=n){
            return ma;
        }
        deque<int>q;
        for(auto x:arr){
            q.push_back(x);
        }
        map<int,int>m;
        while(n){
            int a=q.front();
            q.pop_front();
            int b=q.front();
            q.pop_front();
            q.push_front(max(a,b));
            q.push_back(min(a,b));
            m[q.front()]++;
            if(m[q.front()]>=k){
                return q.front();
            }
            n--;
        }
        return ma;
    }
};