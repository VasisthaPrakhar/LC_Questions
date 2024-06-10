class Solution {
public:
    int findWinningPlayer(vector<int>& s, int k) {
        int n=s.size();
        deque<pair<int,int>>q;
        for(int i=0;i<n;i++){
            q.push_back({s[i],i});
        }
        if(k>n){
            return max_element(s.begin(),s.end()) -s.begin();
        }
        int c=0,p=-1;
        while(1){
            pair<int,int>a,b;
            a=q.front();
            q.pop_front();
            b=q.front();
            q.pop_front();
            if(a.first>b.first){
                if(a.second==p){
                    c++;
                }else{
                    c=1;
                }
                p=a.second;
                q.push_front(a);
                q.push_back(b);
            }else{
                if(b.second==p){
                    c++;
                }else{
                    c=1;
                }
                p=b.second;
                q.push_front(b);
                q.push_back(a);
            }
            if(c>=k){
                return p;
            }
        }
        return -1;
    }
};