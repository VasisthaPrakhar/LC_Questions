class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& d) {
        int n=d.size();
        sort(d.begin(),d.end());
        vector<int>a(n);
        deque<int>s;
        bool f=true;
        for(int i=0;i<n;i++){
            s.push_back(i);
        }
        int j=0;
        while(s.size()){
            if(f){
                a[s.front()]=d[j++];
                s.pop_front();
                f=!f;
            }else{
                int temp = s.front();
                s.pop_front();
                f=!f;
                s.push_back(temp);
            }
        }
        return a;
    }
};