class Solution {
public:
    int minimumPushes(string word) {
        map<char,int,greater<int>>m;
        int sum=0,n=0;
        for(auto x:word){
           m[x]++;
        }
        priority_queue<int>pq;
        //cout<<m.size()<<endl;
        for(auto x:m){
            pq.push(x.second);
        }
        while(!pq.empty()){
            sum+=pq.top() * ceil((double)(n+1)/8.0);
            n++;
            pq.pop();
        }
        return sum;
    }
};