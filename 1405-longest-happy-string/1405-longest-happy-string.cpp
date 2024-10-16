class Solution {
public:
    bool check(string &s, char ch){
        int n=s.length();
        return ((s[n-2]==ch) && (s[n-1]==ch));
    }
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>>pq;
        if(a>0){
            pq.push({a,'a'});
        }
        if(b>0){
            pq.push({b,'b'});
        }
        if(c>0){
            pq.push({c,'c'});
        }
        string ans="";
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            if(ans.length()>=2 && check(ans,it.second)){
                if(pq.size()==0){
                    break;
                }
                auto it1=pq.top();
                pq.pop();
                pq.push(it);
                it1.first--;
                ans.push_back(it1.second);
                if(it1.first>0)
                  pq.push(it1);
            }else{
                it.first--;
                ans.push_back(it.second);
                if(it.first>0)
                  pq.push(it);
            }
        }
        return ans;
    }
};