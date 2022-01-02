class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int c=0;
        unordered_map<int,int>m;
        for(int i=0;i<time.size();i++){
            int k=60-time[i]%60;
            if(m[k]>0){
                c+=m[k];
            }
            if(time[i]%60==0){
                m[60]++;
            }
            m[time[i]%60]++;
        }
        return c;
    }
};